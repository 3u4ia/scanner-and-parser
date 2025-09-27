CC = g++ -g3
CFLAGS = -g3 -Wall
TARGET2 = P0

OBJS2 = P0.o
OBJS3 = BinaryTreeClass/BinaryTree.o

all: $(TARGET2)
main: $(OBJS2)

$(TARGET2): $(OBJS2) $(OBJS3)
	$(CC) -o $(TARGET2) $(OBJS2) $(OBJS3)

$(OBJS2): P0.cpp
	$(CC) $(CFLAGS) -c P0.cpp -o $(OBJS2)

$(OBJS3): BinaryTreeClass/BinaryTree.cpp BinaryTreeClass/BinaryTree.h
	$(CC) $(CFLAGS) -c BinaryTreeClass/BinaryTree.cpp -o $(OBJS3)

clean:
	/bin/rm -f *.o $(TARGET2) BinaryTreeClass/*.o *.inorder *.preorder *.postorder
