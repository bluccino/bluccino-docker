# makefile to make nrf-docker on Mac M1
MAKEFLAGS += --silent

usage:
	ec -g 'usage:'
	echo  '   make mac-m1   # make docker image for MacOS M1'
	echo  '   make mac-x86  # make docker image for MacOS x86'

mac-m1:
	docker build -t nrfconnect-sdk \
					--build-arg sdk_nrf_revision=v2.3-branch --build-arg arch=arm64 .

mac-x86:
	docker build -t nrfconnect-sdk --build-arg sdk_nrf_revision=v2.3-branch .
