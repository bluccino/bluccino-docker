# makefile to make nrf-docker on Mac M1

mac-m1:
	docker build -t nrfconnect-sdk \
					--build-arg sdk_nrf_revision=v2.3-branch --build-arg arch=arm64 .

mac-x86:
	docker build -t nrfconnect-sdk --build-arg sdk_nrf_revision=v2.3-branch .
