t=10
a=['1 10.30 10.35', '2 10.30 11.40', '1 17.50 18.15', '3 19.00 19.10', '3 02.00 03.00']
b=['4 02.00 03.00', '3 02.30 02.45', '1 09.00 10.45']

# t=10
# a=['1 10.30 10.35', '2 10.30 11.40', '1 17.50 18.15', '4 02.30 03.00', '3 02.00 03.00']
# b = ['4 02.00 03.00', '3 02.30 02.45', '1 09.00 10.45']

def solution(t, a, b):
  # Your solution starts here.
    from datetime import datetime
    for i in a:
        sm = []
        for j in b:
            if i.split()[0] != j.split()[0]:
                continue
            jst = j.split()[1].replace('.', ':')
            jen = j.split()[2].replace('.', ':')

            jst = datetime.strptime(jst, '%H:%M')
            jen = datetime.strptime(jen, '%H:%M')

            if ((jen - jst).total_seconds()) / 60 < t:
                continue

            # print(j)
            # ((datetime.strptime(i.split()[1].replace('.', ':'), '%H:%M') - datetime.strptime(j.split()[1].replace('.', ':'), '%H:%M')).total_seconds() / 60) >= t:
            if i.split()[1] <= j.split()[2] and i.split()[2] >= j.split()[1]:
                if j.split()[1] >= i.split()[1] and j.split()[2] <= i.split()[2]:
                    sm.append(j)
    if not sm:
        print("No time to play")
    else:
        for i in sm:
            print(i)

# solution(t,a,b)


def find_matching_time(A, B, duration):
    # Convert duration to hours and minutes
    duration_hours = duration // 60
    duration_minutes = duration % 60

    matching_slots = []

    for a_slot in A:
        # Extract day, start time, and end time for John's slot
        a_day, a_start, a_end = a_slot.split(' ')

        for b_slot in B:
            # Extract day, start time, and end time for Jean's slot
            b_day, b_start, b_end = b_slot.split(' ')

            # Check if the days match
            if a_day == b_day:
                # Convert start and end times to minutes
                a_start_minutes = int(a_start.split('.')[0]) * 60 + int(a_start.split('.')[1])
                a_end_minutes = int(a_end.split('.')[0]) * 60 + int(a_end.split('.')[1])
                b_start_minutes = int(b_start.split('.')[0]) * 60 + int(b_start.split('.')[1])
                b_end_minutes = int(b_end.split('.')[0]) * 60 + int(b_end.split('.')[1])

                # Find overlapping time slot
                start_time = max(a_start_minutes, b_start_minutes)
                end_time = min(a_end_minutes, b_end_minutes)

                # Check if the overlapping slot is long enough for the duration
                if end_time - start_time >= duration:
                    # Convert start and end times back to HH.MM format
                    start_hours = start_time // 60
                    start_minutes = start_time % 60
                    end_hours = (start_time + duration) // 60
                    end_minutes = (start_time + duration) % 60

                    # Append the matching slot to the result list
                    matching_slots.append(f"{a_day} {start_hours:02d}.{start_minutes:02d} - {end_hours:02d}.{end_minutes:02d}")

    return matching_slots


matching_slots = find_matching_time(a, b, t)


print("Matching time slots:")
for slot in matching_slots:
    print(slot)
