mat = [[1,2],[3,4]]
r = 1
c = 4
def reshapeMat(mat,r,c):
	n = len(mat)*len(mat[0])
	if r*c != n:
		return mat
    #initializing the reshaped metrix
    reshaped = [[None]*c for _ in range(r)]
    cur_pos = 0
    for i in range(len(mat)):
    	for j in range(len(mat[0])):
    		reshaped[cur_pos//c][cur_pos%c] = mat[i][j]
    		cur_pos = cur_pos + 1
    return reshaped		
