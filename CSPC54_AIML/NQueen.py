from random import randint

N = 8

#Utility fxn that configures the 2D array board and array state randomly to provide a starting point for the algorithm
#generates the random solution to start hill climbing with
def configureRandomly(board, state):
        #iterating through column indicies
        for i in range(N):
                #getting random row index
                state[i] = randint(0, 100000) % N;
                #placing a queen on that obtained place
                board[state[i]][i] = 1;

# A utility function that prints the 2D array "board".
def printBoard(board):

        for i in range(N):
                print(*board[i])

# A utility function that prints the array "state".
def printState( state):
        print(*state)

# A utility function that compares two arrays, state1 and state2 and returns True if equal and False otherwise.
def compareStates(state1, state2):
        for i in range(N):
                if (state1[i] != state2[i]):
                        return False;
        return True;

#A utility function that fills the array board with values "value"
def fill(board, value):
        for i in range(N):
                for j in range(N):
                        board[i][j] = value;

#calculates the objective value of the state (queens attack each other) using the board
def calculateObjective( board, state):
        #for each queen in a column we check for other queens falling in line of our current queen
        #if found increment attacking count by 1


        #the no of queens attacking each other initially is 0
        attacking = 0;

        for i in range(N):
                #at each col i, the  queen is placed in the row state[i]
                #to the left of the same row  i.e. row remains constant and col decreases

                row = state[i]
                col = i - 1;
                while (col >= 0 and board[row][col] != 1) :
                        col -= 1

                if (col >= 0 and board[row][col] == 1) :
                        attacking += 1;
                
                #to the right of the same row  i.e. row remains constant and col increases
                row = state[i]
                col = i + 1;
                while (col < N and board[row][col] != 1):
                        col += 1;

                if (col < N and board[row][col] == 1) :
                        attacking += 1;
                
                                
                #diagonally to the left up i.e. row and column simultaneously decrease
                row = state[i] - 1
                col = i - 1;
                while (col >= 0 and row >= 0 and board[row][col] != 1) :
                        col-= 1;
                        row-= 1;

                if (col >= 0 and row >= 0 and board[row][col] == 1) :
                        attacking+= 1;

                #digaonally to the right down i.e. row and column simultaneously increase

                row = state[i] + 1
                col = i + 1;
                while (col < N and row < N and board[row][col] != 1) :
                        col+= 1;
                        row+= 1;

                if (col < N and row < N and board[row][col] == 1) :
                        attacking += 1;

                #digaonally to the left down i.e. row decreases and column increase
                row = state[i] + 1
                col = i - 1;
                while (col >= 0 and row < N and board[row][col] != 1) :
                        col -= 1;
                        row += 1;

                if (col >= 0 and row < N and board[row][col] == 1) :
                        attacking += 1;

                #digaonally to the right up i.e. row increases and column decreases
                row = state[i] - 1
                col = i + 1;
                while (col < N and row >= 0 and board[row][col] != 1) :
                        col += 1;
                        row -= 1;

                if (col < N and row >= 0 and board[row][col] == 1) :
                        attacking += 1;
#return pairs
        return int(attacking / 2);


def generateBoard( board, state):
        fill(board, 0);
        for i in range(N):
                board[state[i]][i] = 1;


def copyState( state1, state2):

        for i in range(N):
                state1[i] = state2[i];


def getNeighbour(board, state):


        opBoard = [[0 for _ in range(N)] for _ in range(N)]
        opState = [0 for _ in range(N)]

        copyState(opState, state);
        generateBoard(opBoard, opState);

        opObjective = calculateObjective(opBoard, opState);

        NeighbourBoard = [[0 for _ in range(N)] for _ in range(N)]

        NeighbourState = [0 for _ in range(N)]
        copyState(NeighbourState, state);
        generateBoard(NeighbourBoard, NeighbourState);


        for i in range(N):
                for j in range(N):


                        if (j != state[i]) :


                                NeighbourState[i] = j;
                                NeighbourBoard[NeighbourState[i]][i] = 1;
                                NeighbourBoard[state[i]][i] = 0;


                                temp = calculateObjective( NeighbourBoard, NeighbourState);



                                if (temp <= opObjective) :
                                        opObjective = temp;
                                        copyState(opState, NeighbourState);
                                        generateBoard(opBoard, opState);


                                NeighbourBoard[NeighbourState[i]][i] = 0;
                                NeighbourState[i] = state[i];
                                NeighbourBoard[state[i]][i] = 1;

        # Copying the optimal board and
        # state thus found to the current
        # board and, state since c+= 1 doesn't
        # allow returning multiple values.
        copyState(state, opState);
        fill(board, 0);
        generateBoard(board, state);

def hillClimbing(board, state):

        neighbourBoard = [[0 for _ in range(N)] for _ in range(N)]
        neighbourState = [0 for _ in range(N)]

        copyState(neighbourState, state);
        generateBoard(neighbourBoard, neighbourState);

        while True:

                copyState(state, neighbourState);
                generateBoard(board, state);

                # Getting the optimal neighbour

                getNeighbour(neighbourBoard, neighbourState);

                if (compareStates(state, neighbourState)) :

                        # If neighbour and current are
                        # equal then no optimal neighbour
                        # exists and therefore output the
                        # result and break the loop.

                        printBoard(board);
                        break;

                elif (calculateObjective(board, state) == calculateObjective( neighbourBoard,neighbourState)):


                        neighbourState[randint(0, 100000) % N] = randint(0, 100000) % N;
                        generateBoard(neighbourBoard, neighbourState);

if __name__ == "__main__":
    state = [0] * N
    board = [[0 for _ in range(N)] for _ in range(N)]
    configureRandomly(board, state);
    hillClimbing(board, state);
