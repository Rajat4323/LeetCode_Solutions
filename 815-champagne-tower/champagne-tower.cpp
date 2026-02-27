class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // Create a 2D array to store the amount of champagne flowing through each glass
        vector<vector<double>> tower(101, vector<double>(101, 0.0));
        
        // Pour all champagne into the top glass
        tower[0][0] = poured;
        
        // Simulate the flow
        for (int row = 0; row <= query_row; row++) {
            for (int col = 0; col <= row; col++) {
                // If this glass has more than 1 cup, excess flows down
                if (tower[row][col] > 1.0) {
                    double excess = tower[row][col] - 1.0;
                    tower[row][col] = 1.0;  // Glass can only hold 1 cup
                    
                    // Split excess equally to the two glasses below
                    tower[row + 1][col] += excess / 2.0;
                    tower[row + 1][col + 1] += excess / 2.0;
                }
            }
        }
        
        // Return the amount in the queried glass (capped at 1.0)
        return min(1.0, tower[query_row][query_glass]);
    }
};