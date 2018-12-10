#include <iostream>

enum class Month {jan=1, feb, mar, apr,
		  may, jun, jul, aug,
		  sep, oct, nov, dec};

Month& operator++(Month& m) {
  switch(m) {
  case Month::jan: return m = Month::feb;
  case Month::feb: return m = Month::mar;
  case Month::mar: return m = Month::apr;
  case Month::apr: return m = Month::may;
  case Month::may: return m = Month::jun;
  case Month::jun: return m = Month::jul;
  case Month::jul: return m = Month::aug;
  case Month::aug: return m = Month::sep;
  case Month::sep: return m = Month::oct;
  case Month::oct: return m = Month::nov;
  case Month::nov: return m = Month::dec;
  case Month::dec: return m = Month::jan;
  }
}

class Date {

 private:
  int _day;
  Month _month;
  int _year;

  void add_day();
  
 public:
  Date(const int day, const Month month, const int year);
  int day() const {return _day;}
  Month month() const {return _month;}
  int year() const {return _year;}
  void add_days(const unsigned int n);
  void print_date() {std::cout << _day << " " << int(_month) << " " << _year << std::endl;}
  
};

Date::Date(const int day, const Month month, const int year)
  : _day{day}, _month{month}, _year{year} {}

bool is_leap(const int year) {
  return year % 4 == 0 && year % 400 != 0;
}

void Date::add_day(){
  switch(_month) {
  case Month::jan: case Month::mar: case Month::may:
  case Month::jul: case Month::aug: case Month::oct: case Month::dec:
    if (_day < 31) {
      _day++;
      return;
    }
    break;
  case Month::apr: case Month::jun: case Month::sep:
  case Month::nov:
    if (_day < 30) {
      _day++;
      return;
    }
    break;
  case Month::feb:
    if ((is_leap(_year) && _day < 29) || (!is_leap(_year) && _day < 28)) {
      _day++;
      return;
    }
    break;
  }
  _day = 1;
  if (_month == Month::dec) ++_year;
  ++_month;
  return;
}

void Date::add_days(const unsigned int n) {
  for (unsigned int i = 0; i < n; ++i)
    add_day();
}

bool operator==(const Date& lhs, const Date& rhs) {
  return lhs.day() == rhs.day() &&
    lhs.month() == rhs.month() &&
    lhs.year() == rhs.year();
}

bool operator!=(const Date& lhs, const Date& rhs) {
  return !operator==(lhs, rhs);
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
  os << d.day() << "/" << int(d.month()) << "/" << d.year() << std::endl;
  return os;
}


int main() {
  Date d0(28, Month::feb, 1997);
  Date d1(28, Month::feb, 1998);
  std::cout << int(d0==d1) << std::endl;
  d0.add_days(5);
  std::cout << d0;
  return 0;
}
