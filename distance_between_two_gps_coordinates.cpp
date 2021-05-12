#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

// C++ program to calculate Distance
// Between Two Points on Earth

long double DegToRadians(const long double degree)
{
  long double one_deg = (M_PI) / 180;
  return (one_deg * degree);
}

long double Distance(long double lat1, long double long1, long double lat2,
                     long double long2)
{
  lat1 = DegToRadians(lat1);
  long1 = DegToRadians(long1);
  lat2 = DegToRadians(lat2);
  long2 = DegToRadians(long2);

  // Haversine Formula
  long double dlong = long2 - long1;
  long double dlat = lat2 - lat1;

  long double ans =
      2 * std::asin(std::sqrt(std::pow(std::sin(dlat / 2), 2) +
                              std::cos(lat1) * cos(lat2) *
                              std::pow(std::sin(dlong / 2), 2)));

  // Radius of Earth in
  // Kilometers, R = 6371
  long double R = 6371;

  // Calculate the result
  ans = ans * R;

  // Answer in meters
  return ans * 1000;
}

std::pair<long double, long double> CalculateDesiredCoordinates(const long double desired_distance,
                                                                const long double actual_distance,
                                                                const std::vector<long double> &coordinates)
{
  const long double lat = coordinates[0] + (coordinates[2] - coordinates[0]) * desired_distance / actual_distance;
  const long double lon = coordinates[1] + (coordinates[3] - coordinates[1]) * desired_distance / actual_distance;
  return {lat, lon};
}

// Driver Code
int main()
{
  std::string latlon1, latlon2;
  std::cout << "FROM coordinates (lat,lon): ";
  std::cin >> latlon1;
  std::cout << "TO coordinates (lat,lon): ";
  std::cin >> latlon2;

  std::stringstream ss{latlon1 + "," + latlon2};
  std::vector<long double> coordinates;

  while (ss.good())
  {
    std::string substr;
    std::getline(ss, substr, ',');
    coordinates.push_back(static_cast<long double>(stold(substr)));
  }

  // Call the distance function
  std::cout << std::setprecision(15) << std::fixed;
  auto actual_distance = Distance(coordinates[0], coordinates[1], coordinates[2], coordinates[3]);
  std::cout << std::setprecision(3) << std::fixed;
  std::cout << actual_distance << " m" << std::endl;

  // Choose a desired distance from the starting points
  std::string des_dist;
  std::cout << "Desired distance from starting point: ";
  std::cin >> des_dist;

  auto desired_distance = static_cast<long double>(stold(des_dist));

  // Calculating the new coordinates
  const auto new_coordinates = CalculateDesiredCoordinates(desired_distance, actual_distance, coordinates);

  std::cout << std::setprecision(15) << std::fixed;
  std::cout << "The new coordinates are: " << new_coordinates.first << "," << new_coordinates.second << std::endl;
  return 0;
}
