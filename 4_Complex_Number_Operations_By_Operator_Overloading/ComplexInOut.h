#pragma once
#include <iostream>
#include "Complex.h"

using namespace std;

istream& operator >>(istream &in, Complex &c);
ostream& operator <<(ostream &out, Complex &c);
