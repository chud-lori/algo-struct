class Elevator:
    def __init__(self, id, total_floors):
        self.id = id
        self.current_floor = 0
        self.target_floors = []
        self.direction = 'idle'
        self.queue = []
        self.total_floors = total_floors

    def move(self):
        if self.target_floors:
            if self.direction == 'up':
                self.current_floor += 1
            elif self.direction == 'down':
                self.current_floor -= 1

            if self.current_floor in self.target_floors:
                print(f"Elevator {self.id} stopping at floor {self.current_floor}")
                self.target_floors.remove(self.current_floor)

            if not self.target_floors and self.queue:
                self.target_floors.append(self.queue.pop(0))
                self.update_direction()

            if not self.target_floors:
               self.direction = 'idle'

    def add_request(self, floor):
        if floor not in self.target_floors and floor not in self.queue:
            if self.direction == 'idle' or ((self.direction == 'up' and floor > self.current_floor) or (self.direction == 'down' and floor < self.current_floor)):
                self.target_floors.append(floor)
                self.target_floors.sort(reverse=(self.direction == 'down'))
                self.update_direction()
            else:
                self.queue.append(floor)
            #If self.direction == 'idle':
            #    self.direction = 'up' if floor > self.current_floor else 'down'

    def update_direction(self):
        if self.target_floors:
            if self.target_floors[0] > self.current_floor:
                self.direction = 'up'
            elif self.target_floors[0] < self.current_floor:
                self.direction = 'down'

    def __str__(self):
        return (f"Elevator {self.id} | Current Floor: {self.current_floor} | "
                f"Direction: {self.direction} | Target Floors: {self.target_floors}")


class ElevatorSystem:
    def __init__(self, num_elevators, total_floors):
        self.elevators = [Elevator(i, total_floors) for i in range(num_elevators)]
        self.total_floors = total_floors

    def request_elevator(self, floor, direction):
        best_elevator = None
        min_distance = float('inf')
        for elevator in self.elevators:
            if elevator.direction == 'idle' or elevator.direction == direction:
                distance = abs(elevator.current_floor - floor)
                if distance < min_distance:
                    min_distance = distance
                    best_elevator = elevator
        if best_elevator:
            best_elevator.add_request(floor)
            return f'Elevator {best_elevator.id} assigned to floor {floor}'
        else:
            closest_elevator = min(self.elevators, key=lambda e: abs(e.current_floor - floor))
            closest_elevator.queue.append(floor)
            return f"Floor {floor} added to queue of Elevator {closest_elevator.id}"

    def step(self):
        for elevator in self.elevators:
            elevator.move()

    def display_status(self):
        for elevator in self.elevators:
            print(elevator)

# Example Usage
if __name__ == "__main__":
    # Initialize system with 3 elevators and 10 floors
    system = ElevatorSystem(num_elevators=1, total_floors=10)

    # Request elevators
    print(system.request_elevator(5, 'up'))
    print(system.request_elevator(3, 'down'))
    print(system.request_elevator(8, 'up'))
    print(system.request_elevator(1, 'down'))

    # Simulate the system
    print("\nInitial Status:")
    system.display_status()

    print("\nSimulating Movement:")
    for _ in range(10):  # Simulate 10 time steps
        system.step()
        system.display_status()
        print("-" * 40)
