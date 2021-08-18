#include <iostream>
#include <vector>

int main(){

    // create 3 by 4 2D vector
    std::vector<std::vector<int>> grid(3, std::vector<int>(4,0));

    // resize a member array, jagged array
    grid[1].push_back(1);

    for(int row=0;row<grid.size();row++){
        for(int col=0;col<grid[row].size();col++)
            std::cout << grid[row][col] << std::flush;
        std::cout << std::endl;
    }

    return 0;
}