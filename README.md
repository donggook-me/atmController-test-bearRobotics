# ATM Controller

## Description

This project implements a simple ATM controller in C++. It provides essential functionalities such as inserting a card, entering a PIN, selecting an account, checking balance, depositing, and withdrawing funds. The implementation uses a mock external API for simulating PIN validation and account operations. The ATM controller is designed to be extensible, allowing connection to different bank systems using a factory pattern.

## Project Structure

The project structure is organized as follows:

- **`atm_controller.h`, `atm_controller.cpp`:** Implements the `ATMController` class, which manages ATM operations.
- **`bank_api.h`, `bank_api.cpp`:** Defines the `BankAPI` interface and provides a mock implementation (`MockBankAPI`) for testing purposes.

- **`bank_factory.h`, `bank_factory.cpp`:** Defines the `BankFactory` interface and implements a mock version (`MockBankFactory`) to create instances of `BankAPI`.

- **`test_atm_controller.cpp`:** Contains unit tests using the Google Test framework to validate `ATMController` functionalities.

## How to Build and Run Tests

To build and test the project, follow these steps:

1. **Clone the repository:**
   ```bash
   git clone <repository_url>
   cd <repository_directory>


2. **Compile:**
    Compile all necessary source files (atm_controller.cpp, bank_api.cpp, bank_factory.cpp, test_atm_controller.cpp) into an executable named atm_controller.

    ```bash
    g++ -o atm_controller atm_controller.cpp bank_api.cpp bank_factory.cpp test_atm_controller.cpp

3. **Run Tests:**

    ```bash
    ./atm_controller
