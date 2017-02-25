# microWebStorage

After a challenge to build the tiniest Docker container appeared on the internet, I decided to see how small I could build a Docker container that served an actual purpose. So I ripped the web server code from my InfraKit plugin and built a tiny binary that will sit on a port and act like a simple webserver allowing data stored with a POST and then retrieved with a GET. 

All data that is passed to the container is held in memory and once the container exits there is nothing left on disk. 

## To build
The **Makefile** has two `CFLAGS` lines that can be commented/uncommented allowing you to build either a dynamic binary (requires a libc present, more on that later), or a static binary that is completely self contained.

Do a `git clone` of the url above and then change to the directory containing the `Makefile`, edit as needed and then simply do a `make` and a binary will be created. 

## Build a container
An example Dockerfile below will created a simple tiny Docker container:

```
FROM scratch
ADD microWebStorage /
CMD ["/microWebStorage"]
```

```
$ docker images microwebstorage
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
microwebstorage     latest              28cb98174282        30 minutes ago      14.7 kB
```


## Running the container

### Dynamic binary
So the smallest option is the dynamic binary option however it will require a libc in order to run, this dependancy can be resolved because the main host will already need a libc and we can pass it through with `-v /lib64:/lib64:ro` This mapping will ensure that all of the libraries from the OS are present inside the container allowing the binary to run.

### Environment variables

**mwsPort** - *REQUIRED* This is used to specify which port the server will bind too.

**mwsContentType** - This optional variable can be used to specify the Content-Type returned when doing a GET

### Example startup command
This will start the container and expose the containers ports on the host itself, we pass in an environment variable to start the container on that particular port and we map the lib64 directory so that libc is present. 

`docker run --rm -p 8888:8888 -v /lib64:/lib64:ro -it -e "mwsPort=8888" microwebstorage` 

## Using the container
Once the container is up and running it can make use of simple HTTP **POST** and **GET** commands to store and retrieve data. The container will store this data in memory, so when the container exists any data will be lost. 

```
$ curl -X POST -d '<html> Hello </html>' 192.168.0.25:8888
$ curl 192.168.0.25:8888
<html> Hello </html>
```

The application can be used to hold any data (although text data has only been tested so far) and supports the "EXPECT : 100" allowing large pieces of data to be uploaded,stored and then retrieved. 