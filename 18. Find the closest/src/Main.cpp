#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

const int DIMENSION = 2; // Number of dimensions (x and y)

struct Node
{
    array<int, DIMENSION> position; // Position of the obstacle
    Node *left, *right; // Pointers to left and right children
    
    Node(int x, int y)
    {
        position = {x, y};
        left = right = NULL;
    }
};

// Function to insert a new obstacle into the k-d tree
Node* insert(Node *root, int x, int y, int depth = 0)
{
    if (root == NULL)
        return new Node(x, y);
    
    int current_dimension = depth % DIMENSION; // Determine which dimension to compare
    
    if (x < root->position[current_dimension]) // Insert in left subtree
        root->left = insert(root->left, x, y, depth + 1);
    else // Insert in right subtree
        root->right = insert(root->right, x, y, depth + 1);
    
    return root;
}

// Function to find the closest obstacle to a given position
int findClosestObstacle(Node *root, int player_position[], int depth = 0, int min_distance = INT_MAX, int min_index = -1)
{
    if (root == NULL)
        return min_index;
    
    int x_distance = player_position[0] - root->position[0]; // Calculate distance between x-coordinates
    int y_distance = player_position[1] - root->position[1]; // Calculate distance between y-coordinates
    int distance = sqrt(x_distance * x_distance + y_distance * y_distance); // Calculate distance using distance formula
    
    // Update minimum distance and index if necessary
    if (distance < min_distance)
    {
        min_distance = distance;
        min_index = root->position[0];
    }
    
    int current_dimension = depth % DIMENSION; // Determine which dimension to compare
    
    // Recursively search the subtree with the point closest to the player's position
    if (player_position[current_dimension] < root->position[current_dimension])
    {
        min_index = findClosestObstacle(root->left, player_position, depth + 1, min_distance, min_index);
        
        // Only search the right subtree if the current minimum distance is larger than the distance between the player's position and the splitting plane
        if (abs(player_position[current_dimension] - root->position[current_dimension]) < min_distance)
            min_index = findClosestObstacle(root->right, player_position, depth + 1, min_distance, min_index);
    }
    else
    {
        min_index = findClosestObstacle(root->right, player_position, depth + 1, min_distance, min_index);
        
        // Only search the left subtree if the current minimum distance is larger than the distance between the player's position and the splitting plane
        if (abs(player_position[current_dimension] - root->position[current_dimension]) < min_distance)
            min_index = findClosestObstacle(root->left, player_position, depth + 1, min_distance, min_index);
    }
    
    return min_index;
}

int main()
{
    vector<array<int,2>> obstacle_position = {{11, 42}, {36, 43}, {44, 45}, {46, 47}, {48, 49}, {32, 33}, {34, 35}, {36, 37}, {38, 28}, {42, 21}, {25, 30}, {25, 35}, {16, 22}, {23, 24}, 
    {25, 26}, {27, 28}, {25, 35}, {25, 35}, {6, 18}, {31, 35}, {35, 35}, {4, 28}, {43, 2}, {16, 25}, {25, 25}};
    int player_position[2] = {11, 42};
    
    Node *root = NULL; // Create an empty k-d tree
    
    // Insert all the obstacles into the k-d tree
    for (int i = 0; i < obstacle_position.size(); i++)
        root = insert(root, obstacle_position[i][0], obstacle_position[i][1]);
    
    int closest_obstacle = findClosestObstacle(root, player_position);
    
    cout << "The closest obstacle is at index " << closest_obstacle << " with coordinates (" << obstacle_position[closest_obstacle][0] << ", " << obstacle_position[closest_obstacle][1] << ")" << endl;
    
    return 0;
}

