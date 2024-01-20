heroes = [
    ["Law", "Ogre", "Kuma", "Mokujin", "Julia", "True Ogre", "Paul"],
    ["Xiaoyu", "Yoshimitsu", "Nina", "", "King", "Lei", "Jin"],
    ["Hwoarang", "Doctor B", "", "", "", "Anna", "Eddy"]
]

position = [1, 5] # row 1, col 5 (index start 0)

moves = ["left", "left"]
moves = ["left", "up", "up"]

from typing import *
def solution(heroes: List[str], position: List[int], moves: List[str]):
    rowlen = len(heroes)
    collen = len(heroes[0])
    move_counter = 0
    curpos = position.copy()

    while move_counter < len(moves):

        if moves[move_counter] == "up":
            curpos[0] = (curpos[0] - 1) % rowlen
        if moves[move_counter] == "down":
            curpos[0] = (curpos[0] + 1) % rowlen
        if moves[move_counter] == "left":
            curpos[1] = (curpos[1] - 1) % collen
        if moves[move_counter] == "right":
            curpos[1] = (curpos[1] + 1) % collen
        move_counter += 1

    while heroes[curpos[0]][curpos[1]] == "":
        if moves[len(moves)-1] != "left":
            # anything unless `left` will go right
            curpos[1] = (curpos[1] + 1) % collen
        else:
            # left will go left
            curpos[1] = (curpos[1] - 1) % collen

    return heroes[curpos[0]][curpos[1]]


def test_empty_selected():
    moves = ["left", "left"]
    hero = solution(heroes, position, moves)
    assert hero == "Nina", f"Salah, harusnya Nina, bukan {hero}"
    print("test_empty_selected TRUE")

def test_out_index():
    moves = ["left", "up", "up"]
    hero = solution(heroes, position, moves)
    assert hero == "Anna", f"Salah, harusnya Anna, bukan {hero}"
    print("test_out_index TRUE")

#print(solution(heroes, position, moves))
if __name__ ==  "__main__":
    test_empty_selected()
    test_out_index()

