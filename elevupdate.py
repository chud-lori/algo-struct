class Elevator:
    def __init__(self, elevator_id, total_floors):
        self.elevator_id = elevator_id
        self.current_floor = 0
        self.target_floors = []
        self.direction = 'idle'  # 'up', 'down', or 'idle'
        self.total_floors = total_floors

    def move(self):
        if self.target_floors:
            # Determine direction if not already set
            if self.direction == 'idle':
                self.update_direction()

            # Move one step in the current direction
            if self.direction == 'up':
                self.current_floor += 1
            elif self.direction == 'down':
                self.current_floor -= 1

            # Stop if reached a target floor
            if self.current_floor in self.target_floors:
                print(f"Elevator {self.elevator_id} stopping at floor {self.current_floor}")
                self.target_floors.remove(self.current_floor)

            # Update direction if no more target floors
            if not self.target_floors:
                self.direction = 'idle'

    def add_target_floor(self, floor):
        if floor not in self.target_floors:
            self.target_floors.append(floor)
            self.target_floors.sort(reverse=(self.direction == 'down'))

            # Update direction if idle
            if self.direction == 'idle':
                self.update_direction()

    def update_direction(self):
        if self.target_floors:
            if self.target_floors[0] > self.current_floor:
                self.direction = 'up'
            elif self.target_floors[0] < self.current_floor:
                self.direction = 'down'

    def __str__(self):
        return (f"Elevator {self.elevator_id} | Current Floor: {self.current_floor} | "
                f"Direction: {self.direction} | Target Floors: {self.target_floors}")


class ElevatorSystem:
    def __init__(self, num_elevators, total_floors):
        self.elevators = [Elevator(i, total_floors) for i in range(num_elevators)]
        self.total_floors = total_floors

    def request_elevator(self, requested_floor):
        # Assign an elevator to handle the request
        best_elevator = None
        min_distance = float('inf')

        for elevator in self.elevators:
            if elevator.direction == 'idle' or (
                (elevator.direction == 'up' and requested_floor >= elevator.current_floor) or
                (elevator.direction == 'down' and requested_floor <= elevator.current_floor)
            ):
                distance = abs(elevator.current_floor - requested_floor)
                if distance < min_distance:
                    min_distance = distance
                    best_elevator = elevator

        if best_elevator:
            best_elevator.add_target_floor(requested_floor)
            return f"Elevator {best_elevator.elevator_id} assigned to floor {requested_floor}"
        else:
            # Add to the closest elevator, even if direction doesn't match
            closest_elevator = min(self.elevators, key=lambda e: abs(e.current_floor - requested_floor))
            closest_elevator.add_target_floor(requested_floor)
            return f"Floor {requested_floor} added to Elevator {closest_elevator.elevator_id}"

    def step(self):
        for elevator in self.elevators:
            elevator.move()

    def display_status(self):
        for elevator in self.elevators:
            print(elevator)


# Example Usage
if __name__ == "__main__":
    # Initialize system with 2 elevators and 10 floors
    system = ElevatorSystem(num_elevators=2, total_floors=10)

    # Users press their destination floors
    print(system.request_elevator(5))  # Elevator 0 should handle this
    print(system.request_elevator(3))  # Elevator 0 should handle this while moving to floor 5
    print(system.request_elevator(8))  # Elevator 1 should handle this
    print(system.request_elevator(1))  # Elevator 1 should handle this while moving to floor 8

    # Simulate the system
    print("\nInitial Status:")
    system.display_status()

    print("\nSimulating Movement:")
    for _ in range(10):  # Simulate 10 time steps
        system.step()
        system.display_status()
        print("-" * 40)

