#include <csv.h>
#include <iostream>
#include <csv2/reader.hpp>

using namespace std;

int main() {
  csv2::Reader<delimiter<','>, 
               quote_character<'"'>, 
               first_row_is_header<true>,
               trim_policy::trim_whitespace> csv;
               
  if (csv2.mmap("Mall_Customers.csv")) {
    const auto header = csv2.header();
    for (const auto row: csv2) {
      for (const auto cell: row) {
        // Do something with cell value
        // std::string value;
        // cell.read_value(value);
      }
    }
  }
}