IMAGE_TAG=farmalg

# make build path={folder}
build:
	docker build -t $(IMAGE_TAG) . --build-arg path=$(path)
	@make remove-images

# make run path={folder}
run:
	docker run -it --rm --name $(path) $(IMAGE_TAG)

# make build PATH={new_folder}
new:
	mkdir $(path)
	cp main.c $(path)/main.c

remove-images:
	docker image prune -f
