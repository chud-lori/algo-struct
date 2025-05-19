from typing import List
import pdb

def fullJustifyOld(words: List[str], maxWidth: int) -> List[str]:
    line = ""
    container = []
    for i in range(0, len(words)):
        if len(line + words[i]) >= maxWidth:
            container.append(line)
            line = ""

        if line == "":
            line += words[i]
        else:
            line += " " + words[i]

        if i+1 == len(words):
            container.append(line)

    for i in range(0, len(container)):
        sp_line = container[i].split()
        pad_needed = maxWidth - len(container[i])
        pdb.set_trace()
        if len(container[i]) == maxWidth:
            continue
        if len(sp_line) == 1 or i+1 == len(container):
            container[i] += " " * pad_needed
        else:
            if pad_needed >= (len(sp_line)-1):
                space = pad_needed % (len(sp_line)-1)
                if space == 0:
                    space = pad_needed // (len(sp_line) - 1)
                    total_space = pad_needed
                else:
                    quotient = pad_needed // (len(sp_line) - 1)
                    #remainder = pad_needed % len(sp_line) - 1
                    space = quotient
                    total_space = pad_needed
            else:
                pdb.set_trace()
                if (len(sp_line) - 1) > pad_needed:
                    space = pad_needed // pad_needed
                    total_space = pad_needed
                else:

                    space = pad_needed
                    total_space = pad_needed

            container[i] = ""
            for j in range(0, len(sp_line)):
                #pdb.set_trace()
                if total_space == 0:
                    if j == len(sp_line) - 1:
                        container[i] += sp_line[j]
                        continue
                    container[i] += sp_line[j] + " "
                else:
                    if j == len(sp_line) - 1:
                        container[i] += sp_line[j]
                    else:
                        container[i] += sp_line[j] + " " + (" " * int(space))
                        total_space -= space


    return container

def fullJustify(words: list[str], maxWidth: int) -> list[str]:
    result = []
    current_line = []
    current_width = 0

    for word in words:
        # If adding this word exceeds maxWidth, process the current line
        if current_width + len(word) + len(current_line) > maxWidth:
            # Calculate spaces needed
            if len(current_line) == 1:
                # Only one word in the line, left justify
                result.append(current_line[0] + ' ' * (maxWidth - len(current_line[0])))
            else:
                # Multiple words, distribute spaces evenly
                spaces_needed = maxWidth - current_width
                ## space gaps
                gaps = len(current_line) - 1

                # Calculate base spaces per gap and extra spaces
                spaces_per_gap = spaces_needed // gaps
                extra_spaces = spaces_needed % gaps

                justified_line = ""
                for i in range(len(current_line) - 1):
                    justified_line += current_line[i]
                    spaces = spaces_per_gap + (1 if i < extra_spaces else 0)
                    justified_line += ' ' * spaces

                justified_line += current_line[-1]
                result.append(justified_line)

            # Reset for new line
            current_line = [word]
            current_width = len(word)
        else:
            current_line.append(word)
            current_width += len(word)

    # Handle the last line (left justified)
    if current_line:
        last_line = ' '.join(current_line)
        result.append(last_line + ' ' * (maxWidth - len(last_line)))

    return result


if __name__ == '__main__':
    words = ["This", "is", "an", "example", "of", "text", "justification."]
    maxWidth = 16
    result = fullJustify(words, maxWidth)
    assert result == ["This    is    an", "example  of text", "justification.  "]

    words = ["What","must","be","acknowledgment","shall","be"]
    maxWidth = 16
    result = fullJustify(words, maxWidth)
    assert result == ["What   must   be", "acknowledgment  ", "shall be        "]

    words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"]
    maxWidth = 20
    result = fullJustify(words, maxWidth)
    assert result == ["Science  is  what we", "understand      well", "enough to explain to", "a  computer.  Art is", "everything  else  we", "do                  "]

    words = ["The","important","thing","is","not","to","stop","questioning.","Curiosity","has","its","own","reason","for","existing."]
    #words = ["own","reason","for","existing."]
    maxWidth = 17
    result = fullJustify(words, maxWidth)
    assert result == ["The     important","thing  is  not to","stop questioning.","Curiosity has its","own   reason  for","existing.        "]
    #print(result)

