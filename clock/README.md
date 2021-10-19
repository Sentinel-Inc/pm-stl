# Performance lib

Simple, Easy and precise time measuring tool;

## [Clock](clock.h) tool

Enables time summarizing clock, that precisely keeps track of time spend in given function across all of it's evokings.
Clock does not add time spend in functions evoked by given function to it's total time. This relationship is presented
by Fun() and Fun2() in example one.

## Usage

To enable Clock 3 things must happen.

1. ### Include statement

~~~c++
#include "clock.h"
~~~

2. ### Create timer object, this can be done in one of three ways

**AUTO_CLOCK**

~~~c++
void Fun() {

  AUTO_CLOCK; // <- statement  starting time measurement in that Fun() function, note that everything before that statement won't be measured 
  // this clock's name will be created by combining file name in witch Fun() is defined and function name itself 
  std::this_thread::sleep_for(std::chrono::seconds(1));
  
}
~~~

**START_CLOCK(***name***)**

~~~c++
void Fun() {

  START_CLOCK("ClockName"); // this clock's name will "ClockName" 
  std::this_thread::sleep_for(std::chrono::seconds(1));
  
}
~~~

**LINE_CLOCK(***measured line***)**
Handy when debugging single function to determine witch line takes the longest to execute

~~~c++
void Fun() {
  
  LINE_CLOCK(std::this_thread::sleep_for(std::chrono::seconds(1));) // <- those clocks will be named after line in witch thy were defined 
  LINE_CLOCK(for(int i = 0 ;i < 100000;i++){std::this_thread::sleep_for(std::chrono::minutes(60));})
  
}
~~~~

3. ### Output results

Results of benchmark can be accessed via console

Function:

~~~c++
int main() {
  Fun(); 
  HalfOfFun();
  DISPLAY_TIMINGS;
  return 0;
}
~~~

Output:

~~~c++
total measured time : 2532994 microseconds [us] 2532.99 milliseconds [ms]       2.53299 seconds [s]
clock_example/Fun       1007134us       39.7606% of total measured time
clock_example/Fun2      1010475us       39.8925% of total measured time
clock_example/HalfOfFun 515385us        20.3469% of total measured time
~~~

Or outputted to file Function:

~~~c++
int main() {
  Fun(); 
  HalfOfFun();
  SAVE_TIMINGS("example1.txt");
  return 0;
}
~~~

Output:

~~~c++
clock_example/Fun	1000309
clock_example/Fun2	1019978
clock_example/HalfOfFun	519978
~~~

## Example

See **Example One** in [clock_example](clock_example.cpp) file for in code usage.

## ROOT

To better visualise generated data, root loader script is attached to tool 
