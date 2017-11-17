#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "car.h"
#include <vector>

std::vector<int> origin = {0,0};
std::vector<int> p1_p = {4, 3};
std::vector<int> p1_d = {8, 0};
std::vector<int> p2_p = {8, 4};
std::vector<int> p2_d = {4, 1};
std::vector<int> p3_p = {20, 20};
std::vector<int> p3_d = {30, 30};

// Tests for each function
TEST_CASE("Instantiation", "[0-0]")
{
    Car c = Car();
    REQUIRE(c.num_passengers == 0);
    REQUIRE(c.speed == 0);
    REQUIRE(c.direction == 0.0);
    REQUIRE(c.gear == 0);
    REQUIRE(c.wipers == 0);
    REQUIRE(c.battery_level == 10);
    REQUIRE(c.rpm == 0);
    REQUIRE(c.on == false);
    REQUIRE(c.head_lights == false);
    REQUIRE(c.interior_lights == false);
    REQUIRE(c.locked == true);
    REQUIRE(c.current_loc == origin);
    REQUIRE(c.destinations.empty());
    REQUIRE(c.passengers.empty());
}
TEST_CASE("Destruction", "[0-1]") 
{
    Car c = Car();
    REQUIRE(true);
}
TEST_CASE("Pickup Request", "[1]")
{
    Car c = Car();
    // It should queue all requests, and only perform those it can. 
    c.charge(8);
    c.pickup_request(p1_p, p1_d, 2); // Should navigate to next point. 
    REQUIRE(c.destinations.size() == 2);
    REQUIRE(c.passengers.size() == 2);
    c.pickup_request(p2_p, p2_d, 3); // Should navigate to next point, thus losing 
    REQUIRE(c.destinations.size() == 2);
    REQUIRE(c.passengers.size() == 2);
    c.passengers.pop();
    c.passengers.pop();
    c.destinations.pop();
    c.destinations.pop();
    c.pickup_request(p3_p, p3_d, 2);
    REQUIRE(c.destinations.size() == 0);
    REQUIRE(c.passengers.size() == 0);
    c.pickup_request(p1_p, p1_d, 7);
    REQUIRE(c.destinations.size() == 0);
}
TEST_CASE("Read Battery", "[2]")
{
    Car c = Car();
    REQUIRE(c.battery_level == 10);
    REQUIRE(c.read_battery() == c.battery_level);
    c.battery_level = 90;
    REQUIRE(c.read_battery() == 90);
    REQUIRE(c.read_battery() == c.battery_level);
}
TEST_CASE("Read Speed", "[3]")
{
    Car c = Car();
    REQUIRE(c.speed == 0);
    REQUIRE(c.read_speed() == c.speed);
    c.speed = 100;
    REQUIRE(c.read_speed() == c.speed);
    REQUIRE(c.read_speed() == 100);
}
TEST_CASE("Shifting", "[4]")
{
    Car c = Car();
    c.rpm = 300;
    c.gear = 0;
    REQUIRE(c.shift().gear == 0);
    c.rpm = 1100;
    REQUIRE(c.shift().gear == 1);
    c.rpm = 200;
    REQUIRE(c.shift().gear == 0);
}
TEST_CASE("Accelerating", "[5]")
{
    Car c = Car();
    c.speed = 0;
    REQUIRE(c.accelerate(10, 100).speed == 100);
    REQUIRE(c.accelerate(10,200).speed == 200);
    REQUIRE(c.accelerate(10, 100).speed == 200);
    REQUIRE(c.accelerate(100, 1000).speed == 1000);
}
TEST_CASE("Decelerating", "[6]")
{
    Car c = Car();
    c.speed = 100;
    REQUIRE(c.decelerate(10, 0).speed == 0);
    c.speed = 100;
    REQUIRE(c.decelerate(10, 200).speed == 100);
    REQUIRE(c.decelerate(10, 10).speed == 10);
    REQUIRE(c.decelerate(100, 0).speed == 0);
}
TEST_CASE("Shifting, Accelerating, Decelerating", "[456]")
{
    Car c = Car();
    c.rpm = 300;
    REQUIRE(c.shift().gear == 0);
    REQUIRE(c.accelerate(10, 100).speed == 100);
    REQUIRE(c.gear == 1);
    REQUIRE(c.accelerate(10, 300).speed == 300);
    REQUIRE(c.gear == 3);
    REQUIRE(c.decelerate(10, 10).speed == 10);
    REQUIRE(c.gear == 1);
    REQUIRE(c.decelerate(5, 0).speed == 0);
    REQUIRE(c.gear == 0);
}
TEST_CASE("Adding trip", "[7]")
{
    Car c = Car();
    c.battery_level = 100;
    c.add_trip({p1_p, p1_d}, 2);
    REQUIRE(c.destinations.size() == 2);
    REQUIRE(c.passengers.size() == 2);
    REQUIRE(c.passengers.front() == 2);
    REQUIRE(c.destinations.front() == p1_p);
    c.add_trip({p2_p, p2_d}, 3);
    REQUIRE(c.destinations.size() == 4);
    REQUIRE(c.passengers.size() == 4);
    c.add_trip({p3_p, p3_d}, 2);
    REQUIRE(c.destinations.size() == 6);
    REQUIRE(c.passengers.size() == 6);
}
TEST_CASE("Checking distances", "[8]")
{
    Car c = Car();
    c.battery_level = 100;
    REQUIRE(c.check_distance(p1_p, p1_d));
    REQUIRE(c.check_distance(p2_p, p2_d));
    REQUIRE_FALSE(c.check_distance(p3_p, p3_d));
}
TEST_CASE("Is home", "[9]")
{
    Car c = Car();
    REQUIRE(c.is_home());
    c.current_loc[0] = 1;
    REQUIRE_FALSE(c.is_home());
}
TEST_CASE("has passengers", "[10]")
{
    Car c = Car();
    REQUIRE_FALSE(c.has_passengers());
    c.num_passengers = 2;
    REQUIRE(c.has_passengers());
}
TEST_CASE("Navigating", "[13]")
{
    Car c = Car();
    // Set battery
    c.battery_level = 100;
    // Test a few different points that it should take
    c.destinations.push(p1_p);
    c.navigate();
    REQUIRE(c.direction == 0.75);
    c.destinations.pop();
    
    c.destinations.push(p2_p);
    c.navigate();
    REQUIRE(c.direction == 0.5);
    c.destinations.pop();
    // Test starting a trip it shouldn't
    c.destinations.push(p3_p);
    c.destinations.push(p3_d);
    c.passengers.push(2);
    c.passengers.push(-2);
}
TEST_CASE("Arriving places", "[14]")
{
    Car c = Car();
    c.arrive();
    REQUIRE(c.battery_level == 30);
    c.battery_level = 100;
    c.destinations.push(p1_p);
    c.destinations.push(p1_d);
    c.passengers.push(2);
    c.passengers.push(-2);
    c.arrive();
    REQUIRE(c.destinations.size() == 1);
    REQUIRE(c.passengers.size() == 1);
    REQUIRE(c.current_loc == p1_p);
    REQUIRE(c.num_passengers == 2);

    c.arrive();
    REQUIRE(c.destinations.size() == 0);
    REQUIRE(c.passengers.size() == 0);
    REQUIRE(c.current_loc == p1_d);
    REQUIRE(c.num_passengers == 0);
}
TEST_CASE("turning on", "[15]")
{
    Car c = Car();
    c.turn_on();
    REQUIRE(c.num_passengers == 0);
    REQUIRE(c.speed == 0);
    REQUIRE(c.gear == 0);
    REQUIRE(c.wipers == 0);
    REQUIRE(c.rpm == 300);
    REQUIRE(c.head_lights == true);
    REQUIRE(c.interior_lights == true);
    REQUIRE(c.locked == false);
}
TEST_CASE("turning off", "[16]") 
{
    Car c = Car();
    c.turn_on();
    c.turn_off();
    REQUIRE(c.rpm == 0);
    REQUIRE(c.head_lights == false);
    REQUIRE(c.interior_lights == false);
    REQUIRE(c.locked == true);
}
TEST_CASE("lock", "[17]")
{
    Car c = Car();
    c.locked = false;
    c.lock();
    REQUIRE(c.locked == true);
    c.lock();
    REQUIRE(c.locked == true);
}
TEST_CASE("unlock", "[18]")
{
    Car c = Car();
    c.locked = true;
    c.unlock();
    REQUIRE(c.locked == false);
    c.unlock();
    REQUIRE(c.locked == false);
}
TEST_CASE("Setting wipers", "[19]")
{
    Car c = Car();
    c.set_wipers(2);
    REQUIRE(c.wipers == 2);
    REQUIRE(c.set_wipers(0).wipers == 0);
    REQUIRE(c.set_wipers(0).wipers == 0);
}
TEST_CASE("Charging", "[20]")
{
    Car c = Car();
    c.battery_level = 10;
    c.charge(1);
    REQUIRE(c.battery_level == 20);
    c.charge(8);
    REQUIRE(c.battery_level == 100);
    c.charge(1);
    REQUIRE(c.battery_level == 100);
    c.charge(100);
    REQUIRE(c.battery_level == 100);
}
TEST_CASE("toggle lights", "[21]")
{
    Car c = Car();
    c.head_lights = false;
    c.interior_lights = false;
    c.toggle_lights(true);
    REQUIRE(c.head_lights == true);
    REQUIRE(c.interior_lights == false);
    c.toggle_lights(false);
    REQUIRE(c.head_lights == true);
    REQUIRE(c.interior_lights == true);
    c.toggle_lights(true);
    c.toggle_lights(false);
    REQUIRE(c.head_lights == false);
    REQUIRE(c.interior_lights == false);
}

// Can be run with ./tests [main]
TEST_CASE("Main Test Case", "[main]") {
    // Create car with 10% battery. 
    Car c = Car();
    // Read battery and speed.
    REQUIRE(c.read_battery() == c.battery_level);
    REQUIRE(c.read_speed() == c.speed);
    REQUIRE(c.read_battery() == 10);
    REQUIRE(c.read_speed() == 0);
    
    // Charge for 8 hours
    c.charge(9);
    REQUIRE(c.read_battery() == 100);
    
    // Turn on
    c.turn_on();
    REQUIRE(c.rpm == 300);
    REQUIRE(c.locked == false);

    // Pickup request 1:
    c.pickup_request({4,3}, {8,0}, 2);
    REQUIRE(c.destinations.size() == 2);
    REQUIRE(c.passengers.size() == 2);
    
    // Navigate
    c.navigate();
    REQUIRE(c.direction == 0.75);
    
    // Accelearte
    c.accelerate(10, 500);
    REQUIRE(c.gear == 4);
    
    // Decelerate
    c.decelerate(100, 20);
    REQUIRE(c.gear == 1);
    c.decelerate(10, 0);
    REQUIRE(c.gear == 0);
    
    // Arrive and pickup
    c.arrive();
    REQUIRE(c.read_battery() == 90);
    REQUIRE(c.destinations.size() == 1);
    REQUIRE(c.passengers.size() == 1);
    REQUIRE(c.num_passengers == 2);
    
    // Request the car can't take
    c.pickup_request({5, 5}, {4, 4}, 2);
    REQUIRE(c.destinations.size() == 1);
    REQUIRE(c.passengers.size() == 1);

    // Navigate again
    c.navigate();
    REQUIRE(c.direction == -0.75);
    
    // Accelerate
    c.accelerate(100, 1000);
    REQUIRE(c.gear == 6);
    
    // Wipers on
    c.set_wipers(2);
    REQUIRE(c.wipers == 2);

    // Decelerate
    c.decelerate(10, 0);
    REQUIRE(c.gear == 0);

    // Wipers off
    c.set_wipers(0);
    REQUIRE(c.wipers == 0);
    
    // Arrive and dropoff
    c.arrive(); 
    REQUIRE(c.destinations.size() == 0);
    REQUIRE(c.passengers.size() == 0);

    // Another it should take
    c.pickup_request({8, 4}, {4, 1}, 2);
    REQUIRE(c.destinations.size() == 2);
    REQUIRE(c.passengers.size() == 2);

    c.navigate();
    REQUIRE(c.direction == 1);
    c.accelerate(10, 500);
    REQUIRE(c.read_speed() == 500);
    c.decelerate(10, 0);
    REQUIRE(c.read_speed() == 0);
    
    c.arrive();

    REQUIRE(c.destinations.size() == 1);
    REQUIRE(c.passengers.size() == 1);

    c.navigate();
    REQUIRE(c.direction == 0.75);
    c.accelerate(10, 500);
    c.decelerate(10, 0);
    c.arrive();
    REQUIRE(c.num_passengers == 0);

    // Request it should not take:
    c.pickup_request({50, 50}, {100, 100}, 2);
    c.pickup_request({2, 2}, {3, 3}, 10);
    REQUIRE(c.destinations.size() == 0);
    REQUIRE(c.passengers.size() == 0);

    // Go home and charge. 
    c.navigate();
    c.accelerate(10, 100);
    c.decelerate(10, 0);
    c.arrive();
}