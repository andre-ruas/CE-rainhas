#ifndef GNUPLOT_H
#define GNUPLOT_H

#include <iostream>
#include <string>


using namespace std;

class gnuplot
{
    public:
        gnuplot()
        {
            gnuplotpipe = popen("gnuplot","w");
            if(!gnuplotpipe)
            {
                cerr << ("Gnuplot not found!\n");
            }
        }
        ~gnuplot()
        {
            fprintf(gnuplotpipe, "exit\n");
            pclose(gnuplotpipe);
        }

        void operator()(const string& command)
        {
            fprintf(gnuplotpipe, "%s\n", command.c_str());
            fflush(gnuplotpipe);

        }

    protected:
        FILE* gnuplotpipe;
        
};






#endif
