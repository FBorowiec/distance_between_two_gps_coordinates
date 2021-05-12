# **Distance between two gps coordinates**

For an easy calculation of the distance in meters between two gps coordinates.

Once you put the two GPS coordinates you can choose a desired distance from the starting point and the script will extrapolate the new GPS coordinates for you. *NOTE*: Good only for short distances / straight lines!

If you want another planet just change the hardcoded radius of 6371 meters! :)

*How to run:*

```bash
g++ -o gps_dist.o distance_between_two_gps_coordinates.cpp -std=c++11 && ./gps_dist.o
```
