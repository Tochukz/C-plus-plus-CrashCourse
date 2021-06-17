#include <cstdio>
#include <stdexcept>
#include <functional>
// #include <exception>

struct SpeedUpdated {
  double velocity_mps;
};

struct CarDetected {
  double distance_m;
  double velocity_mps;
};

struct BrakeCommand {
  double time_to_collision_s;
};

struct ServiceBus {
  void publish(const BrakeCommand&);
};

template<typename T>
struct AutoBrake {
  AutoBrake(const T& publish)
    : publish { publish }, 
      speed_mps {}, 
      collision_threshold_s { 5 } {}

  void observe(const SpeedUpdated& cmd) {
    speed_mps = cmd.velocity_mps;
  }

  void observe(const CarDetected& cmd) {
    const auto relatice_velocity_mps = speed_mps - cmd.velocity_mps;
    const auto time_to_collision_s = cmd.distance_m / relatice_velocity_mps;
    if (time_to_collision_s > 0 && time_to_collision_s <= collision_threshold_s) {
      publish(BrakeCommand { time_to_collision_s });
    }
  }

  void set_collision_threshold_s(double x) {
    if (x < 1) {
      throw std::runtime_error {"Collision less than 1."};
    }
    collision_threshold_s = x;
  }

  double get_collision_threshold_s() const {
    return collision_threshold_s;
  }

  double get_speed_mps() const {
    return speed_mps;
  }

  private: 
    double collision_threshold_s;
    double speed_mps;
    const T& publish;
};

constexpr void assert_that(bool result, const char* message) {
  if (!result) {
    throw std::runtime_error { message };
  }
}

/** Unit Tests */
using BrakeFunc = std::function<void(const BrakeCommand&)>;

void initial_speed_is_zero() {
  BrakeFunc brakeFunc { [](const BrakeCommand&) {} };
  AutoBrake<BrakeFunc> auto_brake { brakeFunc };
  assert_that(auto_brake.get_speed_mps() == 0L, "initial speed must be equal to zero");
}
 
void initial_sensitivity_is_five() {
  BrakeFunc brakeFunc { [](const BrakeCommand&) {}};
  AutoBrake<BrakeFunc> auto_brake { brakeFunc };
  assert_that(auto_brake.get_collision_threshold_s() == 5L, "sensitivity should be 5");
}

void sensitivity_greater_than_1() {
  BrakeFunc brakeFunc { [](const BrakeCommand&) {}};
  AutoBrake<BrakeFunc> auto_brake { brakeFunc };
  try {
    auto_brake.set_collision_threshold_s(0.5L);
  } catch(const std::exception& e) {
    return;
  }
  assert_that(false, "no exception thrown");
}

void speed_is_saved() {
  BrakeFunc brakeFunc { [](const BrakeCommand&) {}};
  AutoBrake<BrakeFunc> auto_brake { brakeFunc };
  auto_brake.observe(SpeedUpdated { 100L });
  assert_that(100L == auto_brake.get_speed_mps(), "speed saved should be 100");
  auto_brake.observe(SpeedUpdated { 50L });
  assert_that(50L == auto_brake.get_speed_mps(), "speed saved should be 50");
  auto_brake.observe(SpeedUpdated { 0L });
  assert_that(0L == auto_brake.get_speed_mps(), "speed saved should be 0");
}

void alert_when_imminent() {
  int brake_commands_published { };
  BrakeFunc breakeFunc { 
    [&brake_commands_published] (const BrakeCommand&) {
      brake_commands_published++;
    }
  };
  AutoBrake<BrakeFunc> auto_brake { breakeFunc };
  auto_brake.set_collision_threshold_s(10L);
  auto_brake.observe(SpeedUpdated { 100L });
  auto_brake.observe(CarDetected { 100L, 0L });
  assert_that(brake_commands_published == 1, "brake commands published should be one");
}

void no_alert_when_not_imminent() {
  int brake_commands_published {};
  BrakeFunc brakeFunc { 
    [&brake_commands_published](const BrakeCommand&) { 
      brake_commands_published++;
    }
  };
  AutoBrake<BrakeFunc> auto_brake { brakeFunc };
  auto_brake.set_collision_threshold_s(2L);
  auto_brake.observe(SpeedUpdated { 100L });
  auto_brake.observe(CarDetected { 1000L, 50L});
  assert_that(brake_commands_published == 0, "brake command published");
}

/** Harness */
void run_test(void(*unit_test)(), const char* name){
  try {
    unit_test();
    printf("[+] Test %s successful.\n", name);
  } catch(const std::exception& e) {
    printf("[-] Test failure in %s. %s, \n", name, e.what());
  }
}

int main() {
  // ServiceBus bus;
  // AutoBrake auto_break { 
  //   [&bus] (const auto& cmd) {
  //     bus.publish(cmd);
  //   }
  // };
  // while (true) {
  //   auto_break.observe(SpeedUpdated { 10L });
  //   auto_break.observe(CarDetected { 250L, 25L });
  // }

  run_test(initial_speed_is_zero, "initial speed should be zero");
  run_test(initial_sensitivity_is_five, "initial sensitivity is 5");
  run_test(sensitivity_greater_than_1, "sensitivity should be greater than 1");
  run_test(speed_is_saved, "speed is saved");
  run_test(alert_when_imminent, "alert when imminent");
  run_test(no_alert_when_not_imminent, "no alert when not imminent");
}