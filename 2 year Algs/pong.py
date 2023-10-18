import pygame
import sys
import random

# Инициализация Pygame
pygame.init()

# Определение размеров экрана
WIDTH, HEIGHT = 1920, 1080

# Создание экрана
screen = pygame.display.set_mode((WIDTH, HEIGHT))

# Определение цветов
WHITE = (255, 255, 255)
BLACK = (0, 25, 0)

# Определение скорости мяча и платформы
BALL_SPEED = 1
PADDLE_SPEED = 1

# Определение классов мяча и платформы
class Ball(pygame.Rect):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.dx = BALL_SPEED
        self.dy = BALL_SPEED

    def move_ball(self):
        self.x += self.dx
        self.y += self.dy

        if self.left < 0 or self.right > WIDTH:
            self.dx *= -1
        if self.top < 0 or self.bottom > HEIGHT:
            self.dy *= -1

class Paddle(pygame.Rect):
    def move_paddle2(self, speed, ai=False):
        if ai:
            if self.centery < ball.centery and random.random() > 0.03: # ИИ ошибается примерно в 3% случаев
                self.y += speed
            elif self.centery > ball.centery and random.random() > 0.03: # ИИ ошибается примерно в 3% случаев
                self.y -= speed
        else:
            keys = pygame.key.get_pressed()
            if keys[pygame.K_UP]:
                self.y -= speed
            if keys[pygame.K_DOWN]:
                self.y += speed

        if self.top <= 0:
            self.top = 0
        if self.bottom >= HEIGHT:
            self.bottom = HEIGHT

    def move_paddle1(self, speed):
        keys = pygame.key.get_pressed()
        if keys[pygame.K_w]:
            self.y -= speed
        if keys[pygame.K_s]:
            self.y += speed

        if self.top <= 0:
            self.top = 0
        if self.bottom >= HEIGHT:
            self.bottom = HEIGHT

# Создание объектов мяча и платформы
ball = Ball(WIDTH // 2, HEIGHT // 2, 20, 20)
paddle1 = Paddle(10, HEIGHT // 2, 10, 50)
paddle2 = Paddle(WIDTH - 20, HEIGHT // 2, 10, 50)

# Создание счетчиков очков для каждого игрока
score1 = score2 = 0
font = pygame.font.Font(None, 36)

# Выбор режима игры: два игрока или один игрок против ИИ
ai_mode = False # По умолчанию установлен режим для двух игроков. Измените это на True для режима одного игрока против ИИ.

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    # Заполнение экрана черным цветом
    screen.fill(BLACK)

    # Перемещение мяча и платформы
    ball.move_ball()
    paddle1.move_paddle1(PADDLE_SPEED)
    paddle2.move_paddle2(PADDLE_SPEED, ai=ai_mode)

    # Обработка столкновений мяча с платформами и обновление счета
    if ball.colliderect(paddle1):
        ball.dx *= -1
    elif ball.colliderect(paddle2):
        ball.dx *= -1
    elif ball.left < 0:
        score2 += 1
        ball.center = (WIDTH // 2, HEIGHT // 2)
    elif ball.right > WIDTH:
        score1 += 1
        ball.center = (WIDTH // 2, HEIGHT // 2)

    # Отрисовка мяча и платформ на экране
    pygame.draw.rect(screen, WHITE, paddle1)
    pygame.draw.rect(screen, WHITE, paddle2)
    pygame.draw.ellipse(screen, WHITE, ball)
    pygame.draw.aaline(screen, WHITE, (WIDTH // 2, 0), (WIDTH // 2, HEIGHT))

    # Отображение счета на экране
    score_text = font.render(str(score1) + " - " + str(score2), True, WHITE)
    screen.blit(score_text, (WIDTH // 2 - score_text.get_width() // 2,
                             HEIGHT // 2 - score_text.get_height() // 2))

    # Обновление дисплея
    pygame.display.flip()
