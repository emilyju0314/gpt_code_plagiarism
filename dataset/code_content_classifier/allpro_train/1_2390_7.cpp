#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
#pragma warning(disable : 4996)
#pragma hdrstop
static constexpr int kDayMonth[12] = {31, 28, 31, 30, 31, 30,
                                      31, 31, 30, 31, 30, 31};
template <typename T, size_t N>
struct MakeVector {};
template <typename T>
struct MakeVector<T, 1> {
  template <typename R = std::vector<T>>
  static R make_vector(std::size_t size, const T& value) {
    return R(size, value);
  }
};
template <typename T>
class IntegerIterator
    : public std::iterator<std::input_iterator_tag, T, std::ptrdiff_t, T*, T> {
 public:
  using value_type = T;
  constexpr explicit IntegerIterator(const value_type value) : value_(value) {}
  IntegerIterator& operator++() {
    ++value_;
    return *this;
  }
  constexpr value_type operator*() const { return value_; }
  constexpr bool operator==(const IntegerIterator rhs) const {
    return value_ == rhs.value_;
  }
  constexpr bool operator!=(const IntegerIterator rhs) const {
    return !(*this == rhs);
  }

 private:
  value_type value_;
};
template <typename T>
class IntegerRange {
 public:
  using const_iterator = IntegerIterator<T>;
  constexpr IntegerRange(const T begin, const T end)
      : begin_(begin), end_(end) {}
  constexpr const_iterator begin() const { return const_iterator(begin_); }
  constexpr const_iterator end() const { return const_iterator(end_); }

 private:
  T begin_;
  T end_;
};
template <typename T>
constexpr IntegerRange<T> range(const T to) {
  return IntegerRange<T>(0, to);
}
template <typename T>
inline bool is_leap_year(const T year) {
  return year % 400 == 0 || (year % 100 != 0 && (year & 3) == 0);
}
constexpr const int BASE_MOD = 1000000007;
template <typename T>
inline T& add_mod(T& a, const T b, const T mod = BASE_MOD) {
  if ((a += b) >= mod) {
    a -= mod;
  }
  return a;
}
template <typename T, T MOD = BASE_MOD>
class ModInt {
 public:
  constexpr ModInt() : ModInt(0) {}

 private:
  T value_;
};
using namespace std;
int __;
struct Date {
  int year;
  int month;
  int day;
  int weekday;
  Date() : year(1970), month(0), day(0), weekday(3) {}
  bool is_leap() const { return is_leap_year(year); }
};
inline int get_days_in_month(const int month, const int year) {
  const int days =
      kDayMonth[month] + (month == 1 && is_leap_year(year) ? 1 : 0);
  return days;
}
struct Moment {
  Date date;
  int hour;
  int minute;
  int second;
  Moment() : date(), hour(0), minute(0), second(0) {}
  friend istream& operator>>(istream& in, Moment& rhs) {
    in >> rhs.second >> rhs.minute >> rhs.hour >> rhs.date.weekday >>
        rhs.date.day >> rhs.date.month;
    if (rhs.date.weekday != -1) {
      --rhs.date.weekday;
    }
    if (rhs.date.day != -1) {
      --rhs.date.day;
    }
    if (rhs.date.month != -1) {
      --rhs.date.month;
    }
    return in;
  }
  void next_month() {
    const int days_rem = get_days_in_month(date.month, date.year) - date.day;
    add_mod(date.weekday, days_rem % 7, 7);
    ++date.month;
    if (date.month == 12) {
      date.month = 0;
      ++date.year;
    }
    date.day = 0;
    hour = 0;
    minute = 0;
    second = 0;
  }
  void next_day() {
    const int days = get_days_in_month(date.month, date.year);
    ++date.day;
    add_mod(date.weekday, 1, 7);
    hour = 0;
    minute = 0;
    second = 0;
    if (date.day == days) {
      next_month();
    }
  }
  void next_hour() {
    ++hour;
    minute = 0;
    second = 0;
    if (hour == 24) {
      next_day();
    }
  }
  void next_minute() {
    ++minute;
    second = 0;
    if (minute == 60) {
      next_hour();
    }
  }
  void next_second() {
    ++second;
    if (second == 60) {
      next_minute();
    }
  }
  void set_month(const int month) {
    bool first = true;
    while (date.month != month || first) {
      first = false;
      next_month();
    }
  }
};
namespace parser {
inline void parse_year(Date& date, long long& time_passed) {
  while (true) {
    const int days = 365 + (date.is_leap() ? 1 : 0);
    const int seconds = days * 86400;
    if (time_passed < seconds) {
      break;
    }
    time_passed -= seconds;
    ++date.year;
    add_mod(date.weekday, days % 7, 7);
  }
}
inline void parse_month(Date& date, long long& time_passed) {
  for (size_t month = 0; month < 12; ++month) {
    const int days = get_days_in_month(month, date.year);
    const int seconds = days * 86400;
    if (time_passed < seconds) {
      break;
    }
    time_passed -= seconds;
    ++date.month;
    add_mod(date.weekday, days % 7, 7);
  }
}
inline void parse_day(Date& date, long long& time_passed) {
  const int seconds = 86400;
  date.day = time_passed / seconds;
  add_mod(date.weekday, date.day % 7, 7);
  time_passed %= seconds;
}
inline Date parse_date(long long& time_passed) {
  Date date;
  parse_year(date, time_passed);
  parse_month(date, time_passed);
  parse_day(date, time_passed);
  return date;
}
inline int parse_hour(long long& time_passed) {
  const int seconds = 3600;
  const int hour = time_passed / seconds;
  time_passed %= seconds;
  return hour;
}
inline int parse_minute(long long& time_passed) {
  const int seconds = 60;
  const int minute = time_passed / seconds;
  time_passed %= seconds;
  return minute;
}
inline int parse_second(long long& time_passed) {
  const int second = time_passed;
  time_passed = 0;
  return second;
}
inline Moment parse_moment(long long time_passed) {
  Moment moment;
  moment.date = parse_date(time_passed);
  moment.hour = parse_hour(time_passed);
  moment.minute = parse_minute(time_passed);
  moment.second = parse_second(time_passed);
  return moment;
}
}  // namespace parser
namespace encoder {
inline long long encode_year(const Date& date) {
  long long time = 0;
  for (int year = 1970; year < date.year; ++year) {
    const int days = 365 + (is_leap_year(year) ? 1 : 0);
    const int seconds = days * 86400;
    time += seconds;
  }
  return time;
}
inline long long encode_month(const Date& date) {
  long long time = 0;
  for (int month = 0; month < date.month; ++month) {
    const int days = get_days_in_month(month, date.year);
    const int seconds = days * 86400;
    time += seconds;
  }
  return time;
}
inline long long encode_day(const Date& date) {
  const int seconds = 86400;
  return date.day * seconds;
}
inline long long encode_date(const Date& date) {
  long long time = 0;
  time += encode_year(date);
  time += encode_month(date);
  time += encode_day(date);
  return time;
}
inline long long encode_hour(const int hour) {
  const int seconds = 3600;
  return hour * seconds;
}
inline long long encode_minute(const int minute) {
  const int seconds = 60;
  return minute * seconds;
}
inline long long encode_second(const int second) { return second; }
inline long long encode_moment(const Moment& moment) {
  long long time = 0;
  time += encode_date(moment.date);
  time += encode_hour(moment.hour);
  time += encode_minute(moment.minute);
  time += encode_second(moment.second);
  return time;
}
}  // namespace encoder
bool test_minute(Moment& good_moment, const Moment& config) {
  Moment cur = good_moment;
  for (int second = cur.second; second < 60; ++second) {
    bool ok = (config.second == -1 || config.second == cur.second);
    if (ok) {
      good_moment = cur;
      return true;
    }
    cur.next_second();
  }
  return false;
}
bool test_hour(Moment& good_moment, const Moment& config) {
  Moment cur = good_moment;
  for (int minute = cur.minute; minute < 60; ++minute) {
    bool ok = (config.minute == -1 || config.minute == cur.minute);
    if (ok && test_minute(cur, config)) {
      good_moment = cur;
      return true;
    }
    cur.next_minute();
  }
  return false;
}
bool test_day(Moment& good_moment, const Moment& config) {
  Moment cur = good_moment;
  for (int hour = cur.hour; hour < 24; ++hour) {
    bool ok = (config.hour == -1 || config.hour == cur.hour);
    if (ok && test_hour(cur, config)) {
      good_moment = cur;
      return true;
    }
    cur.next_hour();
  }
  return false;
}
bool test_month(Moment& good_moment, const Moment& config) {
  const int days =
      get_days_in_month(good_moment.date.month, good_moment.date.year);
  Moment cur = good_moment;
  for (int day = good_moment.date.day; day < days; ++day) {
    bool ok = false;
    if (config.date.day == -1) {
      ok |= (config.date.weekday == -1 ||
             config.date.weekday == cur.date.weekday);
    } else {
      if (config.date.weekday != -1) {
        ok |= (config.date.day == cur.date.day ||
               config.date.weekday == cur.date.weekday);
      } else {
        ok |= (config.date.day == cur.date.day);
      }
    }
    if (ok && test_day(cur, config)) {
      good_moment = cur;
      return true;
    }
    cur.next_day();
  }
  return false;
}
void solve(std::istream& in, std::ostream& out) {
  Moment config;
  in >> config >> __;
  for (int _ : range(__)) {
    long long time_passed;
    in >> time_passed;
    const Moment current_moment = parser::parse_moment(time_passed);
    Moment good_moment = current_moment;
    good_moment.next_second();
    if (config.date.month != -1 &&
        config.date.month != good_moment.date.month) {
      good_moment.set_month(config.date.month);
    }
    while (!test_month(good_moment, config)) {
      if (config.date.month != -1) {
        good_moment.set_month(config.date.month);
      } else {
        good_moment.next_month();
      }
    }
    const long long ans = encoder::encode_moment(good_moment);
    out << ans << endl;
  }
}
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  istream& in = cin;
  ostream& out = cout;
  out << fixed << setprecision(16);
  solve(in, out);
  return 0;
}
