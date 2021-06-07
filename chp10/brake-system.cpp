#include <cstdio>
#include <stdexcept>
#include <functional>
//#include <exception>

struct SpeedUpdate {
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

  void observe(const SpeedUpdate& cmd) {}

  void observe(const CarDetected& cmd) {}

  void set_collision_threshold_s(double x) {
    if (x < 1) {
      throw std::exception {"Collision less than 1."};
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

constexpr void assert_that(bool statement, const char* message) {
  if (!statement) {
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
  } catch(const std::exception&) {
    return;
  }
  assert_that(false, "no exception thrown");
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
  //   auto_break.observe(SpeedUpdate { 10L });
  //   auto_break.observe(CarDetected { 250L, 25L });
  // }

  run_test(initial_speed_is_zero, "initial speed should be zero");
  run_test(initial_sensitivity_is_five, "initial sensitivity is 5");
  run_test(sensitivity_greater_than_1, "sensitivity should be greater than 1");
}