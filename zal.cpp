#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


class circle 
{
    ifstream fIn;
    ofstream fOut;

    vector <double> x;
    vector <double> y;
    vector <double> r;


    
    public:
        circle();
        ~circle();
        void getNumbers();
        void fullIn();
        int pairs();
        int perpendicular();
        void stringOfCircles();
};

circle::circle() 
{
    fIn.open("okregi.txt");
    fOut.open("wyniki_okregi.txt");
}

circle::~circle() 
{
    fIn.close();
    fOut.close();
}

void circle::getNumbers() 
{
    double tempx, tempy, tempr;
    while (!fIn.eof()) 
	{
        fIn >> tempx;
        x.push_back(tempx);
        fIn >> tempy;
        y.push_back(tempy);
        fIn >> tempr;
        r.push_back(tempr);

    }
}

void circle::fullIn() 
{
    int counterI = 0;
    int counterII = 0;
    int counterIII = 0;
    
    for (int i = 0; i < 2000; i++) 
	{
        if (x[i] > 0 && y[i] > 0) 
		{
            if (x[i] - r[i] > 0 && y[i] - r[i] > 0) 
			{
                counterI++;
            }
        }
        
        if (x[i] < 0 && y[i] > 0) 
		{
            if (abs(x[i]) - r[i] > 0 && y[i] - r[i] > 0) 
			{
                counterII++;
            }
        }
        
        if (x[i] < 0 && y[i] < 0) {
            if (abs(x[i]) - r[i] > 0 && abs(y[i]) - r[i] > 0) 
			
			{
                counterIII++;
            }
        }
       
    }
    cout << counterI << endl;
    cout << counterII << endl;
    cout << counterIII << endl;
    
}

int circle::pairs() 
{
    int counter = 0;
    for (int i = 0; i < 2000; i++) 
	{
        for (int j = i+1; j < 2000; j++) 
		{
            
            if (x[i] > 0 && y[i] > 0)
			 {
                if (r[i] == r[j]) 
				{
                    if (x[i] == abs(x[j]) && y[i] == y[j])
					 {
                        counter++;
                    }
                    if (y[i] == abs(y[j]) && x[i] == x[j]) 
					{
                        counter++;
                    }
                }  
            }
            
            if (x[i] < 0 && y[i] > 0) 
			{
                if (r[i] == r[j]) 
				{
                    if (abs(x[i]) == x[j] && y[i] == y[j]) 
					{
                        counter++;
                    }
                    if (x[i] == x[j] && y[i] == abs(y[j])) 
					{
                        counter++;
                    }
                }
               
            }
            
            if (x[i] < 0 && y[i] < 0)
			 {
                if (r[i] == r[j]) 
				{
                    if (x[i] == x[j] && abs(y[i]) == y[j]) 
					{
                        counter++;
                    }
                    if (abs(x[i]) == x[j] && y[i] == y[j]) 
					{
                        counter++;
                    }
                }
                
            }
        }
    }
    return counter;
}

int circle::perpendicular() 
{
    int counter = 0;
    for (int i = 0; i < 2000; i++) 
	{
        for (int j = i + 1; j < 2000; j++) 
		{
            
            if (x[i] > 0 && y[i] > 0) 
			{
                if (r[i] == r[j]) 
				{
                    if (x[i] == abs(y[j]) && y[i] == x[j]) 
					{
                        counter++;
                    }
                    if (y[i] == abs(x[j]) && x[i] == y[j]) 
					{
                        counter++;
                    }
                }
            }
            
            if (x[i] < 0 && y[i] > 0) 
			{
                if (r[i] == r[j]) 
				{
                    if (abs(x[i]) == y[j] && y[i] == x[j]) 
					{
                        counter++;
                    }
                    if (x[i] == y[j] && y[i] == abs(x[j])) 
					{
                        counter++;
                    }
                }

            }
            
            if (x[i] < 0 && y[i] < 0) 
			{
                if (r[i] == r[j]) 
				{
                    if (x[i] == y[j] && abs(y[i]) == x[j]) 
					{
                        counter++;
                    }
                    if (abs(x[i]) == y[j] && y[i] == x[j]) 
					{
                        counter++;
                    }
                }

            }
        }
    }
    return counter;
}

void circle::stringOfCircles() 
{
    int string = 1;
    for (int i = 1; i < 1000; i++) 
	
	{
        double length = sqrt((x[i] - x[i-1])* (x[i] - x[i-1]) + (y[i] - y[i-1])* (y[i] - y[i-1]));
        if (length <= r[i - 1]) 
		{
            if (r[i] + r[i - 1] <= length) 
			{
                cout << string << ",";
                string = 1;
            }
            else 
			{

                string++;
            }
        }
        else 
		{
            if (r[i] - r[i - 1] <= length) 
			{
                cout << string << ",";
                string = 1;
            }
            else 
			{

                string++;
            }
        }
        
    }
}



int main()
{
    circle c1;
    c1.getNumbers();
    cout << "79.1" << endl;
    c1.fullIn();
    cout << "79.2" << endl;
    cout << c1.pairs()<<endl;
    cout << "79.3" << endl;
    c1.stringOfCircles();
}

