import math

# Given point A(10, 10) and distance 5
x0, y0 = 10, 10
r = 5

# List to store the coordinates
coordinates = []

# Loop through every degree from 0 to 359
for degree in range(360):
    # Convert degree to radians
    theta = math.radians(degree)
    
    # Calculate x and y coordinates using parametric equations
    x = x0 + r * math.cos(theta)
    y = y0 + r * math.sin(theta)
    
    # Append the coordinates to the list
    coordinates.append((degree, x, y))

# Print all the coordinates
for coord in coordinates:
    print(f"Coordinate: {coord}")

