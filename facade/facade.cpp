using namespace std;
#include <iostream>
#include <string>

class PopcornPopper
{
    public:
        PopcornPopper(){}
        void on()
        {
            cout<<"Popcorn Popper switched on"<<endl;
        }
        void pop()
        {
            cout<<"Starting to pop popcorns"<<endl;
        }
        void off()
        {
            cout<<"Shutting down Popcorn Popper"<<endl;
        }
};
class TheaterLights
{
    public :
    TheaterLights(){}
    void dim(int brightness)
    {
        cout<<"Dim the lights to brightness "<<brightness<<endl;
    }
    void undim()
    {
        cout<<"Reverting to normal brightness "<<endl;
    }
};
class Screen
{
    public:
    Screen(){}
    void down()
    {
        cout<<"Screen down now"<<endl;
    }
    void up()
    {
        cout<<"Screen is pulled up"<<endl;
    }
};
class Projector
{
    public:
    Projector(){}
    void on()
    {
        cout<<" Projector is switched on"<<endl;
    }
    void wideScreenMode()
    {
        cout<< "Projector is turned to WideScreenMode"<<endl;
    }
    void off()
    {
        cout<<" Projector is switched off"<<endl;
    }
};
class StreamingPlayer
{
    public:
    StreamingPlayer(){}

    void on()
    {
        cout<<"Switching on player"<<endl;
    }

    void play(string movie)
    {
        cout<<"Playing the movie "<<movie<<endl;
    }
    
    void stop()
    {
        cout<<"Stop playing the movie "<<endl;
    }

    void off()
    {
        cout<<"Switching off movie player "<<endl;
    }
};
class HomeTheaterFacade
{
    public:

    StreamingPlayer player;
    Projector projector;
    TheaterLights lights;
    Screen screen;
    PopcornPopper popper;
    
    HomeTheaterFacade(StreamingPlayer &player,Projector &projector,TheaterLights &lights,Screen &screen,PopcornPopper &popper):
    player(player),projector(projector),lights(lights),screen(screen),popper(popper){}

    void watchMovie(string movie)
    {
        cout<<"Get ready to watch a movie..."<<endl;
        popper.on();
        popper.pop();
        lights.dim(10);
        screen.down();
        projector.on();
        projector.wideScreenMode();        
        player.on();        
        player.play(movie);
    }

    void endMovie()
    {
        cout<<"Endinging the movie..."<<endl;
        popper.off();
        lights.undim();
        screen.up();
        projector.off();
        player.stop();
        player.off();
    }
};

int main()
{
    PopcornPopper popper;
    TheaterLights lights;
    Screen screen;
    Projector projector;
    StreamingPlayer player;
    HomeTheaterFacade homeTheather(player,projector,lights,screen,popper);
    homeTheather.watchMovie("Gladiator");
    homeTheather.endMovie();
}