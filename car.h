#include <string>
#include <vector>
#include <queue>

/**
 * A self driving car!!!!
 */


class Car {
private: // This is only for testing purposes! 
public:
    /* Variables */
    int num_passengers;             // Number of current passengers
    int speed;                      // Current speed of the car.
    double direction;               // Essentially, the slope of the line between the car and whatever point it is headed for. 
    int gear;                       // Gear the car is in.
    int wipers;                     // Level of the wipers. (0-9)
    int battery_level;              // Current level of the battery. 
    int rpm;                        // Rotations per minute of the engine.
    bool on;                        // Whether the car is on. 
    bool head_lights;               // Whether head lights are on.
    bool interior_lights;           // Whether interior lights are on.
    bool locked;                    // Whether the car is locked. 
    std::vector<int> current_loc;   // A vector of {x, y} coordinates of the current location of the car. 
    std::queue< std::vector<int> > destinations; // A vector of multiple {x, y} coordinates representing the current trip. 
    std::queue<int> passengers;     // A vector of integers, where positives represent pickups, negatives represent dropoffs. 
    
    //////////////// Things that should be callable /////////////////////////
    Car(int batt_lvl=10);
    ~Car();
    
    Car& pickup_request(std::vector<int> pickup_loc, std::vector<int> drop_loc, int new_passengers);
    
    // Reading various statuses
    int read_battery();
    int read_speed();
    
    ///////////////// Things that would normally be private ////////////////

    Car& shift();

    Car& accelerate(int force, int target_speed);
    Car& decelerate(int force, int target_speed);


    Car& add_trip(std::vector< std::vector<int> > trip_coords, int passengers_to_get);
    
    bool check_distance(std::vector<int> pickup_loc, std::vector<int> drop_loc);
    bool is_home();
    bool has_passengers();
    
    int distance(double x1, double y1, double x2, double y2);

    Car& go_home();
    Car& navigate();
    Car& arrive();

    // Controls whether car is on or off. 
    Car& turn_on();
    Car& turn_off();

    // Toggles locks of the car. 
    Car& lock();
    Car& unlock();

    Car& set_wipers(int level);
    
    Car& charge(int duration);

    Car& toggle_lights(bool exterior);
};