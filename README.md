#  financial_math_calculator_cpp

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)
![Status](https://img.shields.io/badge/Status-In%20Progress-yellow.svg)

## 📝 Description

**The Financial Calculator** is a console project developed in C++ for the Financial Mathematics and Investment Analysis course at the Federal University of Uberlândia. It can perform a wide range of financial calculations. Based on the specifications of a study guide, the program offers tools for Simple Interest and Compound Interest, featuring a robust rate conversion system.

The project is structured modularly to ensure code organization, readability, and maintainability.

## 🚀 Features

The calculator is divided into three main modules:

### Compound Interest Module
- **Core Calculations:**
  - Future Value (FV) Calculation
  - Present Value (PV) Calculation
  - Interest Calculation
  - Interest Rate (i) Calculation
  - Time Period (n) Calculation
- **Advanced Rate Conversion:**
  - **Proportional Rate:** Converts a nominal rate into its corresponding effective rate for a given period.
  - **Nominal Rate:** Calculates the annual nominal rate from a periodic effective rate.
  - **Equivalent Rates:** Converts effective rates between different periods, with a message indicating the conversion direction (e.g., smaller to larger period).
    - Full support for various periods: Daily, Monthly, Bi-monthly, Quarterly, Quadri-monthly, Semi-annually, and Annually.

### Simple Interest Module
- **Core Calculations:**
  - Future Value (FV) Calculation
  - Present Value (PV) Calculation
  - Interest Calculation
  - Interest Rate (i) Calculation
  - Time Period (n) Calculation
- **Discount Rate Conversion:**
  - Converts Commercial Discount Rate to Effective Rate.
  - Converts Effective Rate to Commercial Discount Rate.

### Amortization Systems ![WIP](https://img.shields.io/badge/Status-In%20Progress-yellow.svg)
*This module is currently under development.*
- **Planned Features:**
  - Price System (French Amortization)
  - Constant Amortization System (SAC)

## 🛠️ How to Run the Project

Follow the steps below to compile and run the project in your local environment.

### Prerequisites
- A C++ compiler is required, such as **g++** (usually part of the MinGW suite on Windows or `build-essential` on Linux).

### Compiling and Running
1.  Open a terminal in the project's root folder (`CALCULADORA`).

2.  Run the following command to compile all source files and create the executable in the `output` folder:
    ```bash
    g++ main.cpp utils.cpp juros_simples.cpp juros_compostos.cpp -o output/calculadora
    ```

3.  After a successful compilation, run the program with the command below:

    * **On Windows (PowerShell/CMD):**
        ```bash
        .\output\calculadora
        ```

    * **On Linux or macOS:**
        ```bash
        ./output/calculadora
        ```
4.  Navigate through the interactive menus to perform the desired calculations.

## 📄 Acknowledgments

- This project was developed based on the specifications and examples from the study guide `2ª Parte Calculadora Financeira JC.pdf`, which served as a blueprint for implementing the financial features.

## 👨‍💻 Author

@jkakemi
