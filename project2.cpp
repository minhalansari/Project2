//Project 02
//calculating the juggler sequence
//allows user to input beginning of the range, end of the range, and 1 or 2 to print the sequence
//prints sequence if desired
//also prints highest values in the sequence
#include <iostream>
using std::cout; using std::endl; using std::fixed;
#include <iomanip>
using std::setprecision;
#include <cmath>
using std::pow; using std::floor;


int main(){
    long beg; //smallest value of the range
    long end; //max value of the range
    int print; //1 or 2 to know to print the sequence
    long value; //calculated values in the sequence
    long highestcount = 0;
    long count = 0;
    long highestbeg = 0;
    long highestval = 0;
    long highestval2 =0;
    std::cin>>beg>>end>>print; //input the beginning and ending value of range, and 1 or 2 for printing
   if(beg < 2 or end < 2){ //error if either value of the range is less than two
        cout<<"Error"<<endl;
        beg = -1; //set value equal to this so that it skips the while loop
    }
    if(beg>end){ //error if the beginning value is greater than the end
        cout<<"Error"<<endl;
        beg = -1; //set value equal to this in order to skip while loop
    }
    while(beg<=end and beg != -1){ //main while loop that continues until beginning is later than end value
        
        if (print == 1){ //print beginning of sequence if user wants to print
            cout<<endl;
          cout<<beg<<":";  
        }
        
        value = beg; //set value equal to beg in order to calculate value
        while(value >1){ //while the value is greeater than one
            
            if (long(value)%2 == 0){ //calculates even values and prints
                value = (floor(pow(value, (1.0/2.0))));
                if(print == 1 and count != 0){
                 cout<<","<<value;   
                }
                if(print == 1 and count == 0){ //statement to print first value without the comma
                    cout<<" "<<value;
                }
                if(value> highestval){ //statement to find the highest value in the sequence
                    highestval = value;
                }
                
                count+=1; //counter of values
            
            }
            else{
                value = floor(pow(value, (3.0/2.0))); //statement for odd numbers
                if(print == 1 and count != 0){ //statement for printing values with a comma
                  cout<<","<<value;  
                }
                if(print == 1 and count == 0){ //statement for printing values without a comma
                    cout<<" "<<value;
                }
                if(value> highestval){ //statement for getting highest value
                    highestval = value;
                }
                
                count+=1; //counter of values
            }
        
        }
        
        
        if (count> highestcount){ //statement for getting the highest count
          highestcount = count;
          count = 0; //set count back to zero for the next sequence
          highestbeg = beg;
          highestval2 = highestval;
        }
        else{
            count = 0;
            highestval = 0;
        }
        
        beg = 1 + beg; //add to beg after each sub sequence to eventually end the loop
        
    }
    if(beg != -1){ //at the end of the loop print the highest values
        cout<<endl;
        cout<<highestbeg<<", "<<highestcount<<endl;
        cout<<highestbeg<<", "<<highestval2<<endl;
    }
    
}
  
