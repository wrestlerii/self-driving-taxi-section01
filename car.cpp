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
    return battery_level;
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
    if ((current_loc[0] == 0) && (current_loc[1] == 0)) return true;
    return false;
}

bool Car::has_passengers()
{
    if(num_passengers > 0)
    	{
	    return true;
	}
    else
	{
	    return false;
	}
}

// Calculates distance between two points.
int Car::distance(double x1, double y1, double x2, double y2)
{
    int distance = sqrt(((x1 - x2)^2) + ((y1 - y2)^2))
    return distance;
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
	if (on == false){
	rpm = 0;
	head_lights = false;
	locked = true;
	
	}
    return *this;
}

Car &Car::lock()
{
    locked = true;
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
