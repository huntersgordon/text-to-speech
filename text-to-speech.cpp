#include <iostream>
#include <string>
#include <istream>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>

using namespace std;



int main(){



     string voices[10] = {"Maged ","Samantha ","Yuri ", "Karen ", "Daniel ","veena ","Kanya ","victoria ","Alex ", "Sin-ji "};
     unsigned voicecounter = 1;
     string voice = voices[0];
     string res = "say -v "+voice;
     string words ="";
     bool spacebarwaspressed = false;
     bool wordmode = true;


     struct termios old_tio, new_tio;
        unsigned char c;

        tcgetattr(STDIN_FILENO,&old_tio);

        new_tio=old_tio;

        new_tio.c_lflag &=(~ICANON & ~ECHO);

        tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);

        cout<<"type a normal sentence, spacebar to speak and '*' to quit. '&' to change voices.'@' to toggle wordmode"<<endl;


        do {
             c=getchar();
            // if ((c==' ' && spacebarwaspressed == false) || (c == '\n' && spacebarwaspressed == false)){
            if (((c==' ' && (wordmode == true))|| c == '\n' )&& spacebarwaspressed == false) {
                  res = "say -v " + voice + words;
                  system(res.c_str());
                  res = "say -v " + voice;
                  words ="";
                  spacebarwaspressed = true;
             }
             if (c == '*'){
                  printf("%c",c);
                   break;
              }

               if (c == '!'){

                    spacebarwaspressed = true;

                    wordmode = (wordmode ==true?"false":"true");

                    cout<<"wordmode off"<<endl;

               }

              if (c == '&'){
                   voicecounter++;

                   if (voicecounter == 10) voicecounter = 0;

                   spacebarwaspressed = false;

                   voice = voices[voicecounter];

                   cout<<"voice changed to " + voices[voicecounter]<<endl;

                   }

                 if (c == 127){
                      system("clear");
                      words = "";
                      spacebarwaspressed = true;
                 }


             if (c!=' ' && c!='\n' && c != '&' && c!= '!') {
             spacebarwaspressed = false;
             words += c;
        }

        if (c != '&' && c!= 127 && c!= '!')  printf("%c",c);

          }

         while(1);

        /* restore the former settings */
        tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);

        return 0;


return 0;

}
