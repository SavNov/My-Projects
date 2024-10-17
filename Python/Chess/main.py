from re import X
import pygame

pygame.init()

screen_width = 800
screen_height = 800
square_height = screen_height // 8 
square_width = screen_width // 8
screen = pygame.display.set_mode((screen_width, screen_height))
pygame.display.set_caption("My Game")

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
background = pygame.image.load("./chessboard.png")
background = pygame.transform.scale(background, (screen_width, screen_height))
black_pawn = pygame.image.load("black_pawn.png")
black_pawn = pygame.transform.scale(black_pawn, (square_width, square_height))

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
                    mouse_x, mouse_y = event.pos
                    self.offset_x = self.rect.x - mouse_x
                    self.offset_y = self.rect.y - mouse_y

            elif event.type == pygame.MOUSEBUTTONUP:
                if event.button == 1:
                    mouse_x, mouse_y = event.pos
                    self.rect.x, self.rect.y = ((mouse_x // 100) * 100), ((mouse_y // 100) * 100)
                    self.dragging = False

            elif event.type == pygame.MOUSEMOTION:
                if self.dragging:
                    mouse_x, mouse_y = event.pos
                    self.rect.x = mouse_x + self.offset_x
                    self.rect.y = mouse_y + self.offset_y

sprites = pygame.sprite.Group()

a7bp = Piece(black_pawn, 0 * square_width, 7 * square_height)
b7bp = Piece(black_pawn, 1 * square_width, 7 * square_height)
c7bp = Piece(black_pawn, 2 * square_width, 7 * square_height)
d7bp = Piece(black_pawn, 3 * square_width, 7 * square_height)
sprites.add(a7bp, b7bp, c7bp, d7bp)
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
