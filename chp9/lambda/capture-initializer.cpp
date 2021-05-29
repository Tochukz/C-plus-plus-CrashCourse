#include <cstdio>

int main() {
  char username[] {"johnny67"};
  char email_service[] {"gmail.com"};
  auto email_address = [uname = username, mailer=email_service]() { // (1)
    char* email[40];
    size_t i {};
    while(uname[i]) {
      email[i] = &uname[i];
      i++;
    } 
    char at { '@' };
    email[i] = &at;

    size_t j {};
    while(mailer[j]) {
      i++;
      email[i] = &mailer[j];
      j++;
    }
    return *email;
  };
  
  char* johnny_email = email_address();
  printf("Jonny: %s\n", johnny_email); // Jonny: johnny67
}

/**
 Lambda capture with initialization expression [uname = username] 
*/