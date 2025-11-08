#include <iostream>
#include <queue>
#include <memory>
#include <chrono>

using namespace std;

// Part 1: SensorData Template class
template <typename T>
class SensorData
{
private:
    T sensorReading;
    unsigned int timestamp;

public:
    // Constructor
    SensorData(T value, unsigned int time)
    {
        sensorReading = value;
        timestamp = time;
    }
    // Getters
    T getValue() const { return sensorReading; }
    unsigned int getTimestamp() const { return timestamp; }
};

// Part 2: Sensor Template class
template <typename T>
class Sensor
{
public:
    queue<unique_ptr<SensorData<T>>> dataQueue;

    // Create data with random input and timestamp and push to the queue
    void collectData(T value)
    {
        unsigned int time = static_cast<unsigned int>(
            chrono::duration_cast<chrono::milliseconds>(
                chrono::system_clock::now().time_since_epoch())
                .count());

        auto newData = make_unique<SensorData<T>>(value, time);
        dataQueue.push(move(newData));
    }

    // Process all data in the queue (Printing)
    void processAllData()
    {
        while (!dataQueue.empty())
        {
            cout << "Reading: " << dataQueue.front()->getValue() << " | Timestamp: " << dataQueue.front()->getTimestamp() << std::endl;
            dataQueue.pop();
        }
    }
};

// Part 3: Create specific sensor classes with difference types
class TemperatureSensor : public Sensor<float>
{
public:
    void simulateReadings(int count)
    {
        for (int i = 0; i < count; ++i)
        {
            float randomValue = static_cast<float>(rand() % 1000) / 10.0f; // 0.0–99.9 random
            collectData(randomValue);
        }
    }
};
class DistanceSensor : public Sensor<int>
{
public:
    void simulateReadings(int count)
    {
        for (int i = 0; i < count; ++i)
        {
            int randomValue = rand() % 201; // 0–200 random
            collectData(randomValue);
        }
    }
};

int main()
{
    // Seed the Randomness
    srand(static_cast<unsigned int>(time(0)));

    // Create Sensor Objects
    TemperatureSensor temperatureSensor;
    DistanceSensor distanceSensor;

    // Simulate readings from each sensor
    cout << "Simulating data collection...\n";
    temperatureSensor.simulateReadings(5);
    distanceSensor.simulateReadings(5);

    // Processes The data In The Queue (Printing random value and timestamp)
    cout << "\nTemperature Data (Celsius)\n";
    temperatureSensor.processAllData();
    cout << "\nDistance Data (CM)\n";
    distanceSensor.processAllData();

    cout << "\nReadings Finished.\n";
    return 0;
}