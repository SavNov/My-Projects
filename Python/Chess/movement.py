def wpcan(init_pos, final_pos):
    if (init_pos.row == 1):
        if (final_pos.row != init_pos.row) && (final_pos.row - init_pos.row < 3):

class position:
    def __init__(self, row, col):
        self.row = row
        self.col = col
    def move(self, new_row, new_col):
        self.row = new_row
        self.col = new_col
class piece:
    def __init__(self, piece_type, position):
        self.position = position
        self.piece_type = piece_type

    def can_make_move(self, piece_type, position):
        if (piece_type == WHITE_PAWN):
            return wpcan(self.position, position)
