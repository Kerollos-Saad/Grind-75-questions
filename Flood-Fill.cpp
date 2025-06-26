class Solution {
public:

    void recFill(vector<vector<int>>& image, int x, int y,int base_color, int new_color){

        if(x >= image.size() || y >= image[0].size())
            return;

        if(image[x][y] != base_color)
            return;

        image[x][y] = new_color;

        recFill(image, x-1, y, base_color, new_color);
        recFill(image, x, y-1, base_color, new_color);
        recFill(image, x+1, y, base_color, new_color);
        recFill(image, x, y+1, base_color, new_color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image[sr][sc] == color)
            return image;

        recFill(image, sr, sc, image[sr][sc], color);
        return image;
    }
};