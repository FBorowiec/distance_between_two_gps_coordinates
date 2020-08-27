#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
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

long double Distance(long double lat1, long double long1,
                     long double lat2, long double long2)
{
    lat1 = DegToRadians(lat1);
    long1 = DegToRadians(long1);
    lat2 = DegToRadians(lat2);
    long2 = DegToRadians(long2);

    // Haversine Formula
    long double dlong = long2 - long1;
    long double dlat = lat2 - lat1;

    long double ans = 2 * std::asin(std::sqrt(std::pow(std::sin(dlat / 2), 2) +
                                              std::cos(lat1) * cos(lat2) *
                                                  std::pow(std::sin(dlong / 2), 2)));

    // Radius of Earth in
    // Kilometers, R = 6371
    long double R = 6371;

    // Calculate the result
    ans = ans * R;

    return ans * 1000;
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

    // call the distance function
    // std::cout << setprecision(15) << fixed;
    std::cout << Distance(coordinates[0], coordinates[1],
                          coordinates[2], coordinates[3])
              << " m";

    return 0;
}
