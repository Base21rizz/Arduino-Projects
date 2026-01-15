<table>
  <tr>
    <td width="40%" valign="center" valign="center">
      <b><font size="10">This is the repository for all my Arduino simulation and hardware projects</font></b>
    </td>
    <td width=60%" valign="center">
      <img src="https://raw.githubusercontent.com/Base21rizz/Base21rizz/main/Base21rizz/Intro.gif" width ="100%">
    </td>
  </tr>
</table>

<div align="center">
  
## 1. [The Arduino Matrix Calculator](https://github.com/Base21rizz/Arduino-Projects/tree/main/Calculator) 🧮
### A tactile arithmetic experience powered by ATmega328P

![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Status](https://img.shields.io/badge/Status-Functional-brightgreen?style=for-the-badge)

<img src = "Calculator/Screenshot 2026-01-15 170001.png">

> A simple, robust calculator that handles the basics without the distraction of an OS.

</div>


## 🧐 Why I Built This
I wanted to understand the raw logic behind input processing. Instead of using a phone calculator, I built one from scratch to learn about **matrix scanning**, **state management**, and **LCD driver communication**.

## ⚡ Features
* **Arithmetic Core:** Handles Addition, Subtraction, Multiplication, and Division.
* **Continuous Calculation:** Chain operations (e.g., `5 + 5` then `+ 2` uses the previous result).
* **Error Handling:** Catches division by zero errors.
* **Reset on Demand:** Dedicated `C` button to wipe the memory.


## 🔌 Pinout & Wiring
The code uses specific pin mappings. If you are using an Arduino Uno, note that **Pins 14-17 correspond to Analog Pins A0-A3**.

| Component | Component Pin | Arduino Pin | Notes |
| :--- | :--- | :--- | :--- |
| **LCD Display** | RS | **D12** | |
| | E (Enable) | **D11** | |
| | D4 | **D10** | |
| | D5 | **D9** | |
| | D6 | **D8** | |
| | D7 | **D7** | |
| **Keypad** | Row 1 - 4 | **D2, D3, D4, D5** | |
| | Col 1 | **A3 (D17)** | *Leftmost column* |
| | Col 2 | **A2 (D16)** | |
| | Col 3 | **A1 (D15)** | |
| | Col 4 | **A0 (D14)** | *Rightmost column* |


## 🛠️ How to Run
1.  Clone this repository.
2.  Open `calculator.ino` in the Arduino IDE.
3.  Install the required libraries via Library Manager (`Ctrl+Shift+I`):
    * `Keypad` by Mark Stanley
    * `LiquidCrystal` (Built-in)
4.  Connect your Arduino and hit **Upload**.

## 🎮 Controls
| Key | Function |
| :---: | :--- |
| `0-9` | Enter Numbers |
| `A` | **+** (Add) |
| `B` | **-** (Subtract) |
| `C` | **×** (Multiply) |
| `D` | **÷** (Divide) |
| `#` | **=** (Result) |
| `*` | **Clear** (Reset) |


<div align="center">

**Found this useful?**
⭐ Give this repo a Star!

</div>

<p align="right">
    <small>Developed with ❤️ by <b>Shoumik Islam AKA Base21rizz</b></small>
</p>
