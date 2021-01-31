#include <iostream>
#include <list>

using namespace std;

class DataLog
{
private:
    list<int> logList;
    list<int>::iterator currentState;

public:
    DataLog();
    DataLog(const int &data);
    void addCurrentState(int number);
    void subtractCurrentState(int number);
    void save();
    void undo();
    void redo();

    int getCurrentStateData()
    {
        return *currentState;
    }
    
    void printLog()
    {      
        for (auto i = logList.begin(); i != logList.end(); i++) {
            if(i == currentState) cout << "Current state: ";
            cout << "[ " << *i << " ] => ";
        }
        cout << "END_LOG";
    }
};

DataLog::DataLog()
{
    /*
     * TODO:  add the first state with 0
     */
    logList.push_front(0);
    currentState = logList.begin();
    //currentState = logList.end();
}

DataLog::DataLog(const int &data)
{
    /*
     * TODO:  add the first state with data
     */
    logList.push_front(data);
    currentState = logList.begin();
    //currentState = logList.end();
}

void DataLog::addCurrentState(int number)
{
    /*
     * TODO: Increase the value of current state by number
     */
    *currentState = *currentState + number;
}

void DataLog::subtractCurrentState(int number)
{
    /*
     * TODO: Decrease the value of current state by number
     */
    *currentState = *currentState - number;
}

void DataLog::save()
{
    /*
     * TODO: This function will create a new state, copy the data of the currentState
     *       and move the currentState Iterator to this new state. If there are other states behind the 
     *       currentState Iterator, we delete them all before creating a new state.
     */
    list<int>::iterator it = logList.end();
    it--;
    if (currentState == it) {
        logList.push_back(*currentState);
        currentState++;
    }
    else {
        while (currentState != it) {
            it--;
            logList.pop_back();
        }
        logList.push_back(*currentState);
        currentState++;
    }
}

void DataLog::undo()
{
    /*
     * TODO: Switch to the previous state of the data
     *       If this is the oldest state in the log, nothing changes
     */
    if (currentState != logList.begin()) {
        currentState--;
    }
}

void DataLog::redo()
{
    /*
     * TODO: Switch to the latter state of the data
     *       If this is the latest state in the log, nothing changes
     */
    list<int>::iterator it = logList.end();
    it--;
    if (currentState != it) {
        currentState++;
    }
}

int main()
{
    DataLog log(5);
log.save();
log.addCurrentState(5);
log.save();
log.addCurrentState(5);
log.save();
log.addCurrentState(5);
log.save();
log.addCurrentState(5);
log.redo();
log.addCurrentState(10);
log.save();
log.printLog();
    return 0;
}