from typing import List

class ParkingSpot:
    def __init__(self, id, size):
        self.id = id
        self.size = size
        self.occupied = False
    def __str__(self):
        return f"Spot {self.id} ({self.size}) - {'Occupied' if self.occupied else 'Available'}"


class Vehicle:
    def __init__(self, id, type):
        self.id = id
        self.type = type
        self.size = self.get_size()

    def get_size(self):
        if self.type == 'motorcycle':
            return 'small'
        elif self.type == 'car':
            return 'medium'
        elif self.type == 'bus':
            return 'large'
    def __str__(self):
        return f"Vehicle {self.id} ({self.type})"

class ParkingLot:
    def __init__(self):
        self.spots: List[ParkingSpot] = []

    def add_spot(self, spot: ParkingSpot):
        self.spots.append(spot)

    def find_available_spot(self, vehicle):
        for spot in self.spots:
            if not spot.occupied and self.is_spot_compatible(spot, vehicle):
                return spot
        return None

    def is_spot_compatible(self, spot, vehicle):
        size_order = {'small': 1, 'medium': 2, 'large': 3}
        return size_order[spot.size] >= size_order[vehicle.size]

    def park_vehicle(self, vehicle):
        spot = self.find_available_spot(vehicle)
        if spot:
            spot.occupied = True
            return f"Vehicle {vehicle.id} parked in spot {spot.id}"
        return "no available spot"

    def leave_spot(self, spot_id):
        for spot in self.spots:
            if spot.id == spot_id:
                if spot.occupied:
                    spot.occupied = False
                    return f"spot {spot.id} is now free"
                else:
                    return f"Spot {spot.id} is already empty"
        return "No spot found with id {spot_id}"

    def display(self):
        return "\n".join(str(spot) for spot in self.spots)


# Example Usage
if __name__ == "__main__":
    # Initialize parking lot
    parking_lot = ParkingLot()

    # Add parking spots
    parking_lot.add_spot(ParkingSpot(1, 'small'))
    parking_lot.add_spot(ParkingSpot(2, 'medium'))
    parking_lot.add_spot(ParkingSpot(3, 'large'))

    # Create vehicles
    motorcycle = Vehicle(1, 'motorcycle')
    car = Vehicle(2, 'car')
    bus = Vehicle(3, 'bus')

    # Park vehicles
    print(parking_lot.park_vehicle(motorcycle))
    print(parking_lot.park_vehicle(car))
    print(parking_lot.park_vehicle(bus))

    # Display parking lot status
    print("\nParking Lot Status:")
    print(parking_lot.display())

    # Leave spot
    print("\nLeaving Spot 2:")
    print(parking_lot.leave_spot(2))
    print(parking_lot.park_vehicle(motorcycle))

    # Display parking lot status again
    print("\nParking Lot Status:")
    print(parking_lot.display())

