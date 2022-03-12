build:
	g++ main.cpp ListTeam.cpp player.cpp Team.cpp Queue.cpp -o lanParty

run:
	./lanParty c.in d.in r.out	

clean:
	rm -rf *.o lanParty