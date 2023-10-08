/// 2023 LandinBT
#include <locale>

#include "userinterface.hpp"

int main() {
  setlocale(LC_ALL, "Spanish");
  new UserInterface();
}
