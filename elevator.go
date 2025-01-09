package main

import (
	"fmt"
	"sort"
)

type Elevator struct {
	ID           int
	CurrentFloor int
	TargetFloors []int
	Direction    string // "up", "down", or "idle"
	TotalFloors  int
}

func NewElevator(id, totalFloors int) *Elevator {
	return &Elevator{
		ID:          id,
		CurrentFloor: 0,
		Direction:   "idle",
		TotalFloors: totalFloors,
	}
}

func (e *Elevator) Move() {
	if len(e.TargetFloors) > 0 {
		if e.Direction == "idle" {
			e.updateDirection()
		}

		// Move one step in the current direction
		if e.Direction == "up" {
			e.CurrentFloor++
		} else if e.Direction == "down" {
			e.CurrentFloor--
		}

		// Check if the elevator has reached a target floor
		for i, floor := range e.TargetFloors {
			if floor == e.CurrentFloor {
				fmt.Printf("Elevator %d stopping at floor %d\n", e.ID, floor)
				e.TargetFloors = append(e.TargetFloors[:i], e.TargetFloors[i+1:]...)
				break
			}
		}

		// Update direction if no more target floors
		if len(e.TargetFloors) == 0 {
			e.Direction = "idle"
		}
	}
}

func (e *Elevator) AddTargetFloor(floor int) {
	// Avoid duplicate floor requests
	for _, target := range e.TargetFloors {
		if target == floor {
			return
		}
	}
	e.TargetFloors = append(e.TargetFloors, floor)
	e.sortTargetFloors()
	if e.Direction == "idle" {
		e.updateDirection()
	}
}

func (e *Elevator) updateDirection() {
	if len(e.TargetFloors) > 0 {
		if e.TargetFloors[0] > e.CurrentFloor {
			e.Direction = "up"
		} else if e.TargetFloors[0] < e.CurrentFloor {
			e.Direction = "down"
		}
	}
}

func (e *Elevator) sortTargetFloors() {
	if e.Direction == "down" {
		sort.Sort(sort.Reverse(sort.IntSlice(e.TargetFloors)))
	} else {
		sort.Ints(e.TargetFloors)
	}
}

func (e *Elevator) Status() string {
	return fmt.Sprintf("Elevator %d | Current Floor: %d | Direction: %s | Target Floors: %v",
		e.ID, e.CurrentFloor, e.Direction, e.TargetFloors)
}

type ElevatorSystem struct {
	Elevators   []*Elevator
	TotalFloors int
}

func NewElevatorSystem(numElevators, totalFloors int) *ElevatorSystem {
	elevators := make([]*Elevator, numElevators)
	for i := 0; i < numElevators; i++ {
		elevators[i] = NewElevator(i, totalFloors)
	}
	return &ElevatorSystem{
		Elevators:   elevators,
		TotalFloors: totalFloors,
	}
}

func (es *ElevatorSystem) RequestElevator(floor int) string {
	var bestElevator *Elevator
	minDistance := es.TotalFloors + 1

	for _, elevator := range es.Elevators {
		if elevator.Direction == "idle" || (elevator.Direction == "up" && floor >= elevator.CurrentFloor) ||
			(elevator.Direction == "down" && floor <= elevator.CurrentFloor) {
			distance := abs(elevator.CurrentFloor - floor)
			if distance < minDistance {
				minDistance = distance
				bestElevator = elevator
			}
		}
	}

	if bestElevator != nil {
		bestElevator.AddTargetFloor(floor)
		return fmt.Sprintf("Elevator %d assigned to floor %d", bestElevator.ID, floor)
	}

	// If no suitable elevator, add the request to the closest elevator
	closestElevator := es.Elevators[0]
	minDistance = abs(closestElevator.CurrentFloor - floor)
	for _, elevator := range es.Elevators {
		distance := abs(elevator.CurrentFloor - floor)
		if distance < minDistance {
			minDistance = distance
			closestElevator = elevator
		}
	}
	closestElevator.AddTargetFloor(floor)
	return fmt.Sprintf("Floor %d added to Elevator %d", floor, closestElevator.ID)
}

func (es *ElevatorSystem) Step() {
	for _, elevator := range es.Elevators {
		elevator.Move()
	}
}

func (es *ElevatorSystem) DisplayStatus() {
	for _, elevator := range es.Elevators {
		fmt.Println(elevator.Status())
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func main() {
	// Initialize elevator system with 2 elevators and 10 floors
	system := NewElevatorSystem(2, 10)

	// Request elevators
	fmt.Println(system.RequestElevator(5)) // Elevator 0 should handle this
	fmt.Println(system.RequestElevator(3)) // Elevator 0 should handle this while moving to floor 5
	fmt.Println(system.RequestElevator(8)) // Elevator 1 should handle this
	fmt.Println(system.RequestElevator(1)) // Elevator 1 should handle this while moving to floor 8

	// Simulate elevator steps
	fmt.Println("\nInitial Status:")
	system.DisplayStatus()

	fmt.Println("\nSimulating Movement:")
	for i := 0; i < 10; i++ {
		system.Step()
		system.DisplayStatus()
		fmt.Println("----------------------------")
	}
}

