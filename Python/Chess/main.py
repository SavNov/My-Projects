import pygame

import backend as board

pygame.init()

screen_width = 800
screen_height = 800
square_height = screen_height // 8 
square_width = screen_width // 8
screen = pygame.display.set_mode((screen_width, screen_height))
pygame.display.set_caption("My Game")
game_board = board.Board()

def is_in_grid(x, y):
    row = 0
    col = 0
    identified_y = False
    identified_x = False
    for i in range(square_height, square_height * 8, square_height):
        if (x < i) and (identified_x != True):
            row = x
            identified_x = True
        if (y < i) and (identified_y != True):
            col = y
            identified_y = True
    return row,col
running = True
background = pygame.image.load("./background.png")
background = pygame.transform.scale(background, (screen_width, screen_height))
black_pawn = pygame.image.load("black_pawn.png")
black_pawn = pygame.transform.scale(black_pawn, (square_width, square_height))
black_king = pygame.image.load("black_king.png")
black_king = pygame.transform.scale(black_king, (square_width, square_height))
black_queen = pygame.image.load("black_queen.png")
black_queen = pygame.transform.scale(black_queen, (square_width, square_height))
black_rook = pygame.image.load("black_rook.png")
black_rook = pygame.transform.scale(black_rook, (square_width, square_height))
black_knight = pygame.image.load("black_knight.png")
black_knight = pygame.transform.scale(black_knight, (square_width, square_height))
black_bishop = pygame.image.load("black_bishop.png")
black_bishop = pygame.transform.scale(black_bishop, (square_width, square_height))
white_pawn = pygame.image.load("white_pawn.png")
white_pawn = pygame.transform.scale(white_pawn, (square_width, square_height))
white_king = pygame.image.load("white_king.png")
white_king = pygame.transform.scale(white_king, (square_width, square_height))
white_queen = pygame.image.load("white_queen.png")
white_queen = pygame.transform.scale(white_queen, (square_width, square_height))
white_rook = pygame.image.load("white_rook.png")
white_rook = pygame.transform.scale(white_rook, (square_width, square_height))
white_knight = pygame.image.load("white_knight.png")
white_knight = pygame.transform.scale(white_knight, (square_width, square_height))
white_bishop = pygame.image.load("white_bishop.png")
white_bishop = pygame.transform.scale(white_bishop, (square_width, square_height))
class Piece(pygame.sprite.Sprite):
    def __init__(self, icon, x, y):
        super().__init__()
        self.image = icon
        self.image = pygame.transform.scale(self.image, (square_height, square_width))
        self.rect = self.image.get_rect()
        self.rect.topleft = (x, y)
        self.dragging = False

    def update(self, event_list):
        for event in event_list:
            if event.type == pygame.MOUSEBUTTONDOWN:
                if event.button == 1 and self.rect.collidepoint(event.pos): 
                    self.dragging = True
                    self.initial_x = self.rect.x
                    self.initial_y = self.rect.y
                    self.valid = True
                    mouse_x, mouse_y = event.pos
                    self.offset_x = self.rect.x - mouse_x
                    self.offset_y = self.rect.y - mouse_y

            elif event.type == pygame.MOUSEBUTTONUP:
                if event.button == 1:
                    mouse_x, mouse_y = event.pos
                    if self.valid:
                        self.rect.x, self.rect.y = ((mouse_x // 100) * 100), ((mouse_y // 100) * 100)
                    if not self.valid:
                        self.rect.x, self.rect.y = self.initial_x, self.initial_y
                    self.dragging = False

            elif event.type == pygame.MOUSEMOTION:
                if self.dragging:
                    mouse_x, mouse_y = event.pos
                    self.rect.x = mouse_x + self.offset_x
                    self.rect.y = mouse_y + self.offset_y

sprites = pygame.sprite.Group()

for i in range(0, 8):
    for j in range(0, 8):
        pos = game_board[i,j]
        if (pos == board.WHITE_PAWN):
            sprites.add(Piece(white_pawn, j * square_width, i * square_height));
        if (pos == board.WHITE_BISHOP):
            sprites.add(Piece(white_bishop, j * square_width, i * square_height));
        if (pos == board.WHITE_KING):
            sprites.add(Piece(white_king, j * square_width, i * square_height));
        if (pos == board.WHITE_ROOK):
            sprites.add(Piece(white_rook, j * square_width, i * square_height));
        if (pos == board.WHITE_QUEEN):
            sprites.add(Piece(white_queen, j * square_width, i * square_height));
        if (pos == board.WHITE_KNIGHT):
            sprites.add(Piece(white_knight, j * square_width, i * square_height));
        if (pos == board.BLACK_PAWN):
            sprites.add(Piece(black_pawn, j * square_width, i * square_height));
        if (pos == board.BLACK_BISHOP):
            sprites.add(Piece(black_bishop, j * square_width, i * square_height));
        if (pos == board.BLACK_KING):
            sprites.add(Piece(black_king, j * square_width, i * square_height));
        if (pos == board.BLACK_ROOK):
            sprites.add(Piece(black_rook, j * square_width, i * square_height));
        if (pos == board.BLACK_QUEEN):
            sprites.add(Piece(black_queen, j * square_width, i * square_height));
        if (pos == board.BLACK_KNIGHT):
            sprites.add(Piece(black_knight, j * square_width, i * square_height));



selected_piece = None

while running:
    event_list = pygame.event.get()
    for event in event_list: 
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.MOUSEBUTTONDOWN:
            if event.button == 1:  # Left mouse button
                # Check which sprite was clicked
                for sprite in sprites:
                    if sprite.rect.collidepoint(event.pos):
                        selected_piece = sprite  # Select the clicked sprite
                        break  # Stop checking other sprites once one is selected

        # Handle mouse up event
            elif event.type == pygame.MOUSEBUTTONUP:
                if event.button == 1 and selected_piece:
                    selected_piece.dragging = False  # Stop dragging the sprite
                    selected_piece = None  # Deselect the sprite

    # Update the selected sprite's position if it's being dragged
    if selected_piece is not None:
        selected_piece.update(event_list)
    screen.blit(background, (0,0))
    sprites.draw(screen)
    pygame.display.flip()

    pygame.time.Clock().tick(60)

pygame.quit()
