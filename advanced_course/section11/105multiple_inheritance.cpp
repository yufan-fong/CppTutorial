#include <iostream>

class MusicalInstrument{
public:
    virtual void play(){
        std::cout << "Playing instrument..." << std::endl;
    }

    virtual void reset(){
        std::cout << "Resetting instrument..." << std::endl;
    }

    virtual ~MusicalInstrument(){};

};

class Machine {
public:
    virtual void start(){
        std::cout << "Starting machine..." << std::endl;
    }

    virtual void reset(){
        std::cout << "Resetting machine..." << std::endl;
    }

    virtual ~Machine(){};
};

class Synthesizer: public Machine, public MusicalInstrument{
public:
    virtual ~Synthesizer(){};
};

int main(){
    Synthesizer *pSynth = new Synthesizer();

    pSynth->play();
    pSynth->start();
    pSynth->MusicalInstrument::reset();
    pSynth->Machine::reset();

    delete pSynth;
    return 0;
}