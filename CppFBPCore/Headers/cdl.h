#pragma once

class Cdl {                  // countdown latch
 public:
  Cdl(int ct);
  int wait();  // 1 = deadlock; 0 = count completed
  void count_down();

 private:
  int count;
  boost::mutex mutex;
  boost::condition_variable_any cond_var;
} ;

