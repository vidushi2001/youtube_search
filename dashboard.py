# importing all the required libraries
# using plotly dash for visulaisations
import dash
# the package helps in building interactive components such as year slider used here
import dash_core_components as dcc
# contains all the html components
import dash_html_components as html
# package for input and output
from dash.dependencies import Input, Output

# used for building visualisations
import plotly.express as px
#importing pandas for dealing with dataset
import pandas as pd
# this data shows gdp per capita for different countries in different years 
df = pd.read_csv('https://raw.githubusercontent.com/plotly/datasets/master/gapminderDataFiveYear.csv')

# creating the app object
app = dash.Dash(__name__)

# creating components of the app and styling it 
app.layout = html.Div([
    # heading for the dashboard
    html.H1("DASHBOARD FOR GAPMINDER DATA", style={'textAlign': 'center'}),
    html.Div([dcc.Graph(id='graph-with-slider'),
    # interactive year slider
    dcc.Slider(
        id='year-slider',
        min=df['year'].min(),
        max=df['year'].max(),
        value=df['year'].min(),
        marks={str(year): str(year) for year in df['year'].unique()},
        step=None
    ),
    
    ]),
    
])

# defining call backs
@app.callback(
    Output('graph-with-slider', 'figure'),
    Input('year-slider', 'value'))

# writing function which takes in input and feeds it to the scatter plot    
def update_figure(selected_year):
    filtered_df = df[df.year == selected_year]

    # scatter plot
    fig = px.scatter(filtered_df, x="gdpPercap", y="lifeExp",
                     size="pop", color="continent", hover_name="country",
                     log_x=True, size_max=55)

    fig.update_layout(transition_duration=500)
    
    return fig



if __name__ == '__main__':
    # executing app server
    app.run_server(debug=True)
