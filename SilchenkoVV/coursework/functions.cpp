#include "QString"


double simpleFunctions(QString sign, double first, double second) {
       if (sign == "+") return first + second ;
       if (sign == "-") return first - second ;
       if (sign == "×") return first * second ;
       if (sign == "÷") return first / second;
}
