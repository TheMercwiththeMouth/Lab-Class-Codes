import math

berlin = {"lat":52.5200, "lon": 13.4050}
hamburg = {"lat":53.5511, "lon": 9.9937}
munich = {"lat":48.1351, "lon": 11.5820}
cologne = {"lat":50.9375, "lon": 6.9603}
frankfurt = {"lat":50.1109, "lon": 8.6821}
cities = [berlin, hamburg, munich, cologne, frankfurt]


def distance_between(city1, city2):
    """distance between two cities"""
    lat1, lon1 = city1["lat"], city1["lon"]
    lat2, lon2 = city2["lat"], city2["lon"]
    radius = 6371  # Radius of the Earth in kilometers
    dlat = math.radians(lat2 - lat1)
    dlon = math.radians(lon2 - lon1)
    a = math.sin(dlat / 2) ** 2 + math.cos(math.radians(lat1)) * math.cos(math.radians(lat2)) * math.sin(dlon / 2) ** 2
    c = 2 * math.atan2(math.sqrt(a), math.sqrt(1 - a))
    distance = radius * c
    return distance

def get_distance_matrix(cities):
    """populate distance matrix"""
    num_cities = len(cities)
    distances = [[0] * num_cities for _ in range(num_cities)]
    for i in range(num_cities):
        for j in range(i + 1, num_cities):
            dist = distance_between(cities[i], cities[j])
            distances[i][j] = int(dist)
            distances[j][i] = int(dist)
    return distances


def solve_tsp_nearest(distances):
    num_cities = len(distances)
    visited = [False] * num_cities
    tour = []
    total_distance = 0
    
    # Start at the first city
    current_city = 0
    tour.append(current_city)
    visited[current_city] = True
    
    
    # Repeat until all cities have been visited
    while len(tour) < num_cities:
        nearest_city = None
        nearest_distance = math.inf

        # Find the nearest unvisited city
        for city in range(num_cities):
            if not visited[city]:
                distance = distances[current_city][city]
                if distance < nearest_distance:
                    nearest_city = city
                    nearest_distance = distance

        # Move to the nearest city
        current_city = nearest_city
        tour.append(current_city)
        visited[current_city] = True
        total_distance += nearest_distance

    # Complete the tour by returning to the starting city
    tour.append(0)
    total_distance += distances[current_city][0]

    return tour, total_distance

distances = get_distance_matrix(cities)
distances=[
    [0, 99999, 504, 477, 423],
    [99999, 0, 612, 356, 392],
    [504, 612, 0, 456, 304],
    [477, 356, 456, 0, 152],
    [423, 392, 304, 152, 0]]
for row in distances:
    print(row)

tour, total_distance = solve_tsp_nearest(distances)

print("Tour:", tour)
print("Total distance:", total_distance)
