main.o: main.cpp
	g++ -c main.cpp

board.o: board.cpp
	g++ -c board.cpp

view.o: view.cpp
	g++ -c view.cpp

mask.o: mask.cpp
	g++ -c mask.cpp		

game.o: game.cpp
	g++ -c game.cpp

historique.o: historique.cpp
	g++ -c historique.cpp


main: main.o board.o view.o mask.o game.o historique.o
	g++ main.o board.o view.o mask.o game.o historique.o -o main


test_read_FEN: test_read_FEN.cpp board.cpp view.cpp mask.cpp	
	g++ test_read_FEN.cpp board.cpp view.cpp mask.cpp -o test_read_FEN	


test_write_FEN: test_write_FEN.cpp board.cpp view.cpp mask.cpp	
	g++ test_write_FEN.cpp board.cpp view.cpp mask.cpp -o test_write_FEN	


test_king: test_king.cpp board.cpp view.cpp mask.cpp	
	g++ test_king.cpp board.cpp view.cpp mask.cpp -o test_king	


test_queen: test_queen.cpp board.cpp view.cpp mask.cpp	
	g++ test_queen.cpp board.cpp view.cpp mask.cpp -o test_queen


test_rook: test_rook.cpp board.cpp view.cpp mask.cpp	
	g++ test_rook.cpp board.cpp view.cpp mask.cpp -o test_rook	


test_knight: test_knight.cpp board.cpp view.cpp mask.cpp	
	g++ test_knight.cpp board.cpp view.cpp mask.cpp -o test_knight	


test_pawn: test_pawn.cpp board.cpp view.cpp mask.cpp	
	g++ test_pawn.cpp board.cpp view.cpp mask.cpp -o test_pawn	


test_color_mask: test_color_mask.cpp board.cpp view.cpp mask.cpp	
	g++ test_color_mask.cpp board.cpp view.cpp mask.cpp -o test_color_mask	


test_take: test_take.cpp board.cpp view.cpp mask.cpp	
	g++ test_take.cpp board.cpp view.cpp mask.cpp -o test_take	


test_moveble: test_moveble.cpp board.cpp view.cpp mask.cpp	
	g++ test_moveble.cpp board.cpp view.cpp mask.cpp -o test_moveble	


test_choices: test_choices.cpp board.cpp view.cpp mask.cpp	
	g++ test_choices.cpp board.cpp view.cpp mask.cpp -o test_choices	


test_attaked: test_attaked.cpp board.cpp view.cpp mask.cpp	
	g++ test_attaked.cpp board.cpp view.cpp mask.cpp -o test_attaked	


test_human: test_human.cpp board.cpp view.cpp mask.cpp game.cpp	historique.cpp
	g++ test_human.cpp board.cpp view.cpp mask.cpp game.cpp historique.cpp -o test_human
	

test_computer: test_computer.cpp board.cpp view.cpp mask.cpp game.cpp historique.cpp	
	g++ test_computer.cpp board.cpp view.cpp mask.cpp game.cpp historique.cpp -o test_computer

test_one_run: test_one_run.cpp board.cpp view.cpp mask.cpp game.cpp historique.cpp	
	g++ test_one_run.cpp board.cpp view.cpp mask.cpp game.cpp historique.cpp -o test_one_run
	
test_check: test_check.cpp board.cpp view.cpp mask.cpp game.cpp historique.cpp	
	g++ test_check.cpp board.cpp view.cpp mask.cpp game.cpp historique.cpp -o test_check
	
test_move_check_computer: test_move_check_computer.cpp board.cpp view.cpp mask.cpp game.cpp historique.cpp	
	g++ test_move_check_computer.cpp board.cpp view.cpp mask.cpp game.cpp historique.cpp -o test_move_check_computer	