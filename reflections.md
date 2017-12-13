# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Reflections

### How Parameters were Chosen

Initial parameters of the steering angle controller were set using the PID coeffcients from PID Control lesson (0.2, 0.004, 3) and manually tuning (0.1, 0.002, 2.8).

Then I used twiddle to optimize the parameters, which reduced the erro by about 80%. The twiddle optimized parameters (0.178125,0.0186016,2.55) overall drives smoother but are prone to oscillations (which settles quickly) at the start and at sharp bends.

A second PID controller was used to keep the speed constant.

### Effects of PID Parameters

To see how each parameter effects the dynamic response I varied each parameter one at atime starting from the optimal set of gains.

|Gain|Increased Effect  | Decreased Effect |
|---|---|---|
| P  |Fast oscillations with increasing amplitude <br> The oscillations are unstable and the car goes off track. <br> Steering is too fast for the available damping to reduce osccilations | Slow oscillations with large amplitude. <br>Steering is not fast enough to repond to the changes in CTE |
| I| The car goes off track quickly with a large value. <br> The steering over compensates for small errors.| Even with 0 gain the car drove smoothly <br> This is there to compensate for systematic bias and <br> it appears that there is none. i.e. errors oscillate around 0 <br> making the cumulative error small.  |
|D   | Fast oscillations with small amplitude which grows quickly. <br> It seems the steering is too sluggish to start with heavy damping. <br>  |With decreased damping the car overshoots and goes off <br>track immediately.   |



### Twiddle Log


	isharaka@isharaka-N551JB:~/wk/udacity/sdc/CarND-PID-Control-Project/build (master)*$ ./pid 
	Listening to port 4567
	Connected!!!
	error 0.51287 best 0 best K [6.95027e-310:0:6.95027e-310] K [0.1:0.002:2.8] dK [1:1:1]
	Connected!!!
	error 1.06684 best 0.51287 best K [0.1:0.002:2.8] K [1.1:0.002:2.8] dK [1:1:1]
	Connected!!!
	error 1.20142 best 0.51287 best K [0.1:0.002:2.8] K [-0.9:0.002:2.8] dK [1:1:1]
	Connected!!!
	error 1.02509 best 0.51287 best K [0.1:0.002:2.8] K [0.1:1.002:2.8] dK [0.5:1:1]
	Connected!!!
	error 1.02621 best 0.51287 best K [0.1:0.002:2.8] K [0.1:-0.998:2.8] dK [0.5:1:1]
	Connected!!!
	error 0.73549 best 0.51287 best K [0.1:0.002:2.8] K [0.1:0.002:3.8] dK [0.5:0.5:1]
	Connected!!!
	error 0.41942 best 0.51287 best K [0.1:0.002:2.8] K [0.1:0.002:1.8] dK [0.5:0.5:1]
	Connected!!!
	error 1.09685 best 0.41942 best K [0.1:0.002:1.8] K [0.6:0.002:1.8] dK [0.5:0.5:2]
	Connected!!!
	error 1.00466 best 0.41942 best K [0.1:0.002:1.8] K [-0.4:0.002:1.8] dK [0.5:0.5:2]
	Connected!!!
	error 1.0235 best 0.41942 best K [0.1:0.002:1.8] K [0.1:0.502:1.8] dK [0.25:0.5:2]
	Connected!!!
	error 1.02416 best 0.41942 best K [0.1:0.002:1.8] K [0.1:-0.498:1.8] dK [0.25:0.5:2]
	Connected!!!
	error 0.616083 best 0.41942 best K [0.1:0.002:1.8] K [0.1:0.002:3.8] dK [0.25:0.25:2]
	Connected!!!
	error 1.00277 best 0.41942 best K [0.1:0.002:1.8] K [0.1:0.002:-0.2] dK [0.25:0.25:2]
	Connected!!!
	error 0.681686 best 0.41942 best K [0.1:0.002:1.8] K [0.35:0.002:1.8] dK [0.25:0.25:1]
	Connected!!!
	error 2.01363 best 0.41942 best K [0.1:0.002:1.8] K [-0.15:0.002:1.8] dK [0.25:0.25:1]
	Connected!!!
	error 1.0072 best 0.41942 best K [0.1:0.002:1.8] K [0.1:0.252:1.8] dK [0.125:0.25:1]
	Connected!!!
	error 1.00343 best 0.41942 best K [0.1:0.002:1.8] K [0.1:-0.248:1.8] dK [0.125:0.25:1]
	Connected!!!
	error 0.506625 best 0.41942 best K [0.1:0.002:1.8] K [0.1:0.002:2.8] dK [0.125:0.125:1]
	Connected!!!
	error 0.538354 best 0.41942 best K [0.1:0.002:1.8] K [0.1:0.002:0.8] dK [0.125:0.125:1]
	Connected!!!
	error 0.234208 best 0.41942 best K [0.1:0.002:1.8] K [0.225:0.002:1.8] dK [0.125:0.125:0.5]
	Connected!!!
	error 1.48502 best 0.234208 best K [0.225:0.002:1.8] K [0.225:0.127:1.8] dK [0.25:0.125:0.5]
	Connected!!!
	error 1.02821 best 0.234208 best K [0.225:0.002:1.8] K [0.225:-0.123:1.8] dK [0.25:0.125:0.5]
	Connected!!!
	error 0.212686 best 0.234208 best K [0.225:0.002:1.8] K [0.225:0.002:2.3] dK [0.25:0.0625:0.5]
	Connected!!!
	error 1.01632 best 0.212686 best K [0.225:0.002:2.3] K [0.475:0.002:2.3] dK [0.25:0.0625:1]
	Connected!!!
	error 1.00742 best 0.212686 best K [0.225:0.002:2.3] K [-0.025:0.002:2.3] dK [0.25:0.0625:1]
	Connected!!!
	error 1.17878 best 0.212686 best K [0.225:0.002:2.3] K [0.225:0.0645:2.3] dK [0.125:0.0625:1]
	Connected!!!
	error 1.05741 best 0.212686 best K [0.225:0.002:2.3] K [0.225:-0.0605:2.3] dK [0.125:0.0625:1]
	Connected!!!
	error 0.289688 best 0.212686 best K [0.225:0.002:2.3] K [0.225:0.002:3.3] dK [0.125:0.03125:1]
	Connected!!!
	error 0.225801 best 0.212686 best K [0.225:0.002:2.3] K [0.225:0.002:1.3] dK [0.125:0.03125:1]
	Connected!!!
	error 0.642738 best 0.212686 best K [0.225:0.002:2.3] K [0.35:0.002:2.3] dK [0.125:0.03125:0.5]
	Connected!!!
	error 0.466176 best 0.212686 best K [0.225:0.002:2.3] K [0.1:0.002:2.3] dK [0.125:0.03125:0.5]
	Connected!!!
	error 0.407672 best 0.212686 best K [0.225:0.002:2.3] K [0.225:0.03325:2.3] dK [0.0625:0.03125:0.5]
	Connected!!!
	error 1.04915 best 0.212686 best K [0.225:0.002:2.3] K [0.225:-0.02925:2.3] dK [0.0625:0.03125:0.5]
	Connected!!!
	error 0.262244 best 0.212686 best K [0.225:0.002:2.3] K [0.225:0.002:2.8] dK [0.0625:0.015625:0.5]
	Connected!!!
	error 0.187406 best 0.212686 best K [0.225:0.002:2.3] K [0.225:0.002:1.8] dK [0.0625:0.015625:0.5]
	Connected!!!
	error 0.273767 best 0.187406 best K [0.225:0.002:1.8] K [0.2875:0.002:1.8] dK [0.0625:0.015625:1]
	Connected!!!
	error 0.246591 best 0.187406 best K [0.225:0.002:1.8] K [0.1625:0.002:1.8] dK [0.0625:0.015625:1]
	Connected!!!
	error 0.166273 best 0.187406 best K [0.225:0.002:1.8] K [0.225:0.017625:1.8] dK [0.03125:0.015625:1]
	Connected!!!
	error 0.217143 best 0.166273 best K [0.225:0.017625:1.8] K [0.225:0.017625:2.8] dK [0.03125:0.03125:1]
	Connected!!!
	error 1.08633 best 0.166273 best K [0.225:0.017625:1.8] K [0.225:0.017625:0.8] dK [0.03125:0.03125:1]
	Connected!!!
	error 0.187419 best 0.166273 best K [0.225:0.017625:1.8] K [0.25625:0.017625:1.8] dK [0.03125:0.03125:0.5]
	Connected!!!
	error 0.150993 best 0.166273 best K [0.225:0.017625:1.8] K [0.19375:0.017625:1.8] dK [0.03125:0.03125:0.5]
	Connected!!!
	error 1.03234 best 0.150993 best K [0.19375:0.017625:1.8] K [0.19375:0.048875:1.8] dK [0.0625:0.03125:0.5]
	Connected!!!
	error 1.28994 best 0.150993 best K [0.19375:0.017625:1.8] K [0.19375:-0.013625:1.8] dK [0.0625:0.03125:0.5]
	Connected!!!
	error 1.05025 best 0.150993 best K [0.19375:0.017625:1.8] K [0.19375:0.017625:2.3] dK [0.0625:0.015625:0.5]
	Connected!!!
	error 1.00034 best 0.150993 best K [0.19375:0.017625:1.8] K [0.19375:0.017625:1.3] dK [0.0625:0.015625:0.5]
	Connected!!!
	error 0.223232 best 0.150993 best K [0.19375:0.017625:1.8] K [0.25625:0.017625:1.8] dK [0.0625:0.015625:0.25]
	Connected!!!
	error 0.200619 best 0.150993 best K [0.19375:0.017625:1.8] K [0.13125:0.017625:1.8] dK [0.0625:0.015625:0.25]
	Connected!!!
	error 1.00688 best 0.150993 best K [0.19375:0.017625:1.8] K [0.19375:0.03325:1.8] dK [0.03125:0.015625:0.25]
	Connected!!!
	error 0.226816 best 0.150993 best K [0.19375:0.017625:1.8] K [0.19375:0.002:1.8] dK [0.03125:0.015625:0.25]
	Connected!!!
	error 0.135086 best 0.150993 best K [0.19375:0.017625:1.8] K [0.19375:0.017625:2.05] dK [0.03125:0.0078125:0.25]
	Connected!!!
	error 0.477158 best 0.135086 best K [0.19375:0.017625:2.05] K [0.225:0.017625:2.05] dK [0.03125:0.0078125:0.5]
	Connected!!!
	error 0.136305 best 0.135086 best K [0.19375:0.017625:2.05] K [0.1625:0.017625:2.05] dK [0.03125:0.0078125:0.5]
	Connected!!!
	error 0.198644 best 0.135086 best K [0.19375:0.017625:2.05] K [0.19375:0.0254375:2.05] dK [0.015625:0.0078125:0.5]
	Connected!!!
	error 0.145197 best 0.135086 best K [0.19375:0.017625:2.05] K [0.19375:0.0098125:2.05] dK [0.015625:0.0078125:0.5]
	Connected!!!
	error 0.133031 best 0.135086 best K [0.19375:0.017625:2.05] K [0.19375:0.017625:2.55] dK [0.015625:0.00390625:0.5]
	Connected!!!
	error 0.127208 best 0.133031 best K [0.19375:0.017625:2.55] K [0.209375:0.017625:2.55] dK [0.015625:0.00390625:1]
	Connected!!!
	error 0.154755 best 0.127208 best K [0.209375:0.017625:2.55] K [0.209375:0.0215313:2.55] dK [0.03125:0.00390625:1]
	Connected!!!
	error 0.149596 best 0.127208 best K [0.209375:0.017625:2.55] K [0.209375:0.0137188:2.55] dK [0.03125:0.00390625:1]
	Connected!!!
	error 0.222389 best 0.127208 best K [0.209375:0.017625:2.55] K [0.209375:0.017625:3.55] dK [0.03125:0.00195312:1]
	Connected!!!
	error 0.222752 best 0.127208 best K [0.209375:0.017625:2.55] K [0.209375:0.017625:1.55] dK [0.03125:0.00195312:1]
	Connected!!!
	error 0.182876 best 0.127208 best K [0.209375:0.017625:2.55] K [0.240625:0.017625:2.55] dK [0.03125:0.00195312:0.5]
	Connected!!!
	error 0.125023 best 0.127208 best K [0.209375:0.017625:2.55] K [0.178125:0.017625:2.55] dK [0.03125:0.00195312:0.5]
	Connected!!!
	error 0.132587 best 0.125023 best K [0.178125:0.017625:2.55] K [0.178125:0.0195781:2.55] dK [0.0625:0.00195312:0.5]
	Connected!!!
	error 0.131676 best 0.125023 best K [0.178125:0.017625:2.55] K [0.178125:0.0156719:2.55] dK [0.0625:0.00195312:0.5]
	Connected!!!
	error 0.273388 best 0.125023 best K [0.178125:0.017625:2.55] K [0.178125:0.017625:3.05] dK [0.0625:0.000976562:0.5]
	Connected!!!
	error 0.164975 best 0.125023 best K [0.178125:0.017625:2.55] K [0.178125:0.017625:2.05] dK [0.0625:0.000976562:0.5]
	Connected!!!
	error 0.189507 best 0.125023 best K [0.178125:0.017625:2.55] K [0.240625:0.017625:2.55] dK [0.0625:0.000976562:0.25]
	Connected!!!
	error 0.166161 best 0.125023 best K [0.178125:0.017625:2.55] K [0.115625:0.017625:2.55] dK [0.0625:0.000976562:0.25]
	Connected!!!
	error 0.117775 best 0.125023 best K [0.178125:0.017625:2.55] K [0.178125:0.0186016:2.55] dK [0.03125:0.000976562:0.25]
	Connected!!!
	error 0.119645 best 0.117775 best K [0.178125:0.0186016:2.55] K [0.178125:0.0186016:2.8] dK [0.03125:0.00195312:0.25]
	Connected!!!
	error 0.170275 best 0.117775 best K [0.178125:0.0186016:2.55] K [0.178125:0.0186016:2.3] dK [0.03125:0.00195312:0.25]
	Connected!!!
	
	