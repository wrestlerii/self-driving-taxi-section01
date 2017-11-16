#include "car.h"
#include <string>
#include <vector>
#include <cmath>

Car::Car(int charge)
{
    speed = 0;
    gear = 0;
    wipers = 0;
    num_passengers = 0;
    battery_level = charge;
    rpm = 0;
    on = false;
    head_lights = false;
    interior_lights = false;
    locked = true;
    current_loc = {0, 0};
}

Car::~Car() {}

// REQUIRES OTHER FUNCTIONS
Car &Car::pickup_request(std::vector<int> pickup_coords, std::vector<int> drop_coords, int new_passengers)
{
    return *this;
}

int Car::read_battery()
{
    return 0;
}

int Car::read_speed()
{
    return -10;
}

Car &Car::shift()
{
    return *this;
}

Car &Car::accelerate(int force, int target_speed)
{
    return *this;
}

Car &Car::decelerate(int force, int target_speed)
{
    return *this;
}

Car &Car::add_trip(std::vector<std::vector<int>> coords, int new_passengers)
{
    return *this;
}

bool Car::check_distance(std::vector<int> pickup, std::vector<int> dropoff)
{
    return true;
}

bool Car::is_home() 
{
    return false;
}

bool Car::has_passengers() 
{
    return false;
}

// Calculates distance between two points.
int Car::distance(double x1, double y1, double x2, double y2)
{
    return 0;
}

Car &Car::go_home()
{
    return *this;
}

Car &Car::navigate()
{
    return *this;
}

Car &Car::arrive()
{
    return *this;
}

Car &Car::turn_on()
{
    return *this;
}

Car &Car::turn_off()
{
    return *this;
}

Car &Car::lock()
{
    return *this;
}

Car &Car::unlock()
{
    return *this;
}

Car &Car::set_wipers(int level)
{
    return *this;
}

Car &Car::charge(int duration)
{
    return *this;
}

Car &Car::toggle_lights(bool exterior)
{
    return *this;
}
