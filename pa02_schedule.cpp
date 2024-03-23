#include <iostream>

using namespace std;

class work
{
private:
    int _start;
    int _end;
    int _noise;
public:
    work() : _start(0), _end(0), _noise(0) {}

    int getStart() {return this->_start;}
    int getEnd() {return this->_end;}
    int getNoise() {return this->_noise;}

    void setStart(int start) {this->_start = start;}
    void setEnd(int end) {this->_end = end;}
    void setNoise(int noise) {this->_noise = noise;}

};

class team
{
private:
    int _workNum;
    work** _workAddr;
public:
    team() : _workNum(0), _workAddr(nullptr) {}

    int getWorkNum() {return this->_workNum;}
    work** getWorkAddr() {return this->_workAddr;}

    void setWorkNum(int workNum) {this->_workNum = workNum;}
    void setWorkAddr(work** workAddr) {this->_workAddr = workAddr;}
};

int main()
{
    int amount = 0, workTime = 0;
    int teamNum = 0;
    int workNum = 0;

    int start = 0, end = 0, noise = 0;

    cin >> amount >> workTime;

    int* schedule = new int[workTime - 1];
    int* result_arr = new int[workTime - 1];

    int result = 0;

    cin >> teamNum;

    team* myTeam = new team[teamNum];
    for (int i = 0; i < teamNum; i++)
    {
        cin >> workNum;
        work** myWork = new work*[workNum];

        myTeam[i].setWorkNum(workNum);

        for (int j = 0; j < workNum; j++)
        {
            cin >> start >> end >> noise;

            myWork[j] = new work;

            myWork[j]->setStart(start);
            myWork[j]->setEnd(end);
            myWork[j]->setNoise(noise);

        }
        myTeam[i].setWorkAddr(myWork);
    }

    for (int i = 0; i <= workTime; i++)
    {
        schedule[i] = amount;
        result_arr[i] = 0;
    }
    
    for (int i = 0; i < teamNum; i++)
    {
        for (int j = 0; j < myTeam[i].getWorkNum(); j++)
        {
            for (int k = myTeam[i].getWorkAddr()[j]->getStart(); k < myTeam[i].getWorkAddr()[j]->getEnd(); k++)
            {
                schedule[k] += myTeam[i].getWorkAddr()[j]->getNoise();
                
            }
        }
    }

    result_arr[0] = schedule[0];

    for (int i = 1; i < workTime; i++)
    {
        result_arr[i] = max(0, result_arr[i - 1]) + schedule[i];
    }

    for (int i = 0; i < workTime; i++)
    {
        if (result_arr[i] > result)
        {
            result = result_arr[i];
        }        
    }

    cout << result;

    return 0;
}